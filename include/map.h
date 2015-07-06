#ifndef MAP_H
#define MAP_H

/*!
 * \file map.h
 * \brief controleur de la map
 * \author ROTA - NICOLLE
 */

#include <vector>
#include <pthread.h>
#include <unistd.h>
#include "case.h"

/*! \class Map
* \brief classe initialisant les items et gerant leurs actions ainsi que la creation des threads
*
*  La classe gere la map
*/
class Map
{
protected:
	int taille; /*!< Dimension de la map*/
	int puces; /*!< Nombre de puces sur la map*/
	int case_chien; /*!< Numero de la case du chien*/
	Chien* medor; /*!< Chien*/
	std::vector<Case*> carte; /*!< Liste des cases de la map*/
	pthread_mutex_t mutmut = PTHREAD_MUTEX_INITIALIZER; /*!< Mutex de la map*/

public:
	/*!
	 *  \brief Constructeur
	 *
	 *  Constructeur de la classe Map
	 *
	 *  \param size : dimension de la map
	 *  \param nb_puces : nombre de puces sur la map
	 *  \param toutou : pointeur du chien
	 */
	Map(int size, int nb_puces, Chien* toutou);

	/*!
	 *  \brief Destructeur
	 *
	 *  Destructeur de la classe Map
	 */
	~Map();

	/*!
	 *  \brief Initialisation de la map
	 *
	 *  Methode qui permet de creer la map et d'y placer le chien
	 */
	void init();

	/*!
	 *  \brief Calcul aura
	 *
	 *  Methode qui permet de calculer l'aura de la case en fonction de la position du chien
	 *
	 *  \param x : coordonnee x de la case
	 *  \param y : coordonnee y de la case
	 *
	 *  \return la valeur d'aura de la case
	 */
	int give_aura(int i, int j);

	/*!
	 *  \brief Place une puce sur la map
	 *
	 *  Methode qui permet de placer aleatoirement une puce sur la map
	 *
	 *  \param pupuce : pointeur de la puce que l'on veut placer
	 *
	 *  \return le numero de la case
	 */
	int place_puce(Puce* pupuce);

	/*!
	 *  \brief Creation des threads
	 *
	 *  Methode qui permet de creer un nombre de threads correspondant au nombre de puces sur la map
	 */
	void get_threads();

	/*!
	 *  \brief Travail d'un thread
	 *
	 *  Methode executee dans un thread
	 *
	 *  \param tab : pointeur de la map
	 */
	static void* work_thread(void* tab);

	/*!
	 *  \brief Recuperation de case
	 *
	 *  Methode qui permet d'obtenir un objet case dans la map
	 *
	 *  \param position : numero de la case dans la map
	 *
	 *  \return le pointeur de la case
	 */
	Case* get_case(int position);

	/*!
	 *  \brief Guetteur de position du chien
	 *
	 *  Methode qui permet d'obtenir la position de la case du chien dans la map
	 *
	 *  \return le numero de la case
	 */
	int get_case_chien();

	/*!
	 *  \brief Guetteur de dimension de la map
	 *
	 *  Methode qui permet d'obtenir la dimension de la map
	 *
	 *  \return la dimension de la map
	 */
	int get_size();
};


#endif
