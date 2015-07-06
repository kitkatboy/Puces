#ifndef CASE_H
#define CASE_H

/*!
 * \file case.h
 * \brief proprietes d'une case de la map
 * \author ROTA - NICOLLE
 */

#include <utility>
#include <stdlib.h>
#include <pthread.h>
#include "puce.h"
#include "chien.h"


/*! \class Case
* \brief classe representant une case
*
*  La classe gere le contenu d'une case
*/
class Case
{
protected:
	Puce* insecte = NULL; /*!< Presence puce*/
	Chien* medor = NULL; /*!< Presence chien*/
	int aura; /*!< Aura*/
	std::pair<int, int> coord; /*!< Coordonnees de la case*/
	pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER; /*!< Verouillage case*/

public:
	/*!
	 *  \brief Constructeur
	 *
	 *  Constructeur de la classe Case
	 *
	 *  \param x : coordonnee x de la case
	 *  \param y : coordonnee y de la case
	 *  \param odeur : aura de la case
	 */
	Case(int x, int y, int odeur);

	/*!
	 *  \brief Constructeur
	 *
	 *  Constructeur de la classe Case
	 *
	 *  \param x : coordonnee x de la case
	 *  \param y : coordonnee y de la case
	 *  \param odeur : aura de la case
	 *  \param toutou : chien
	 */
	Case(int x, int y, int odeur, Chien* toutou);

	/*!
	 *  \brief Destructeur
	 *
	 *  Destructeur de la classe Case
	 */
	~Case();

	/*!
	 *  \brief Getteur d'aura
	 *
	 *  Methode qui permet de connaitre l'aura de la case
	 *
	 *  \return la valeur de l'aura de la case
	 */
	int get_aura();

	/*!
	 *  \brief Setteur d'aura
	 *
	 *  Methode qui permet d'attribuer une aura a la case
	 *
	 *  \param val : valeur de l'aura qu'on veut attribuer a la case
	 */
	void set_aura(int val);

	/*!
	 *  \brief Check la presence d'une puce sur la case
	 *
	 *  Methode qui permet de savoir si la case est occupee par une puce
	 *
	 *  \return true si il n'y a pas de puce presente,
	 *  false sinon
	 */
	bool is_no_puce();

	/*!
	 *  \brief Check la presence d'un chien sur la case
	 *
	 *  Methode qui permet de savoir si la case est occupee par un chien
	 *
	 *  \return true si il n'y a pas de chien present,
	 *  false sinon
	 */
	bool is_no_dog();

	/*!
	 *  \brief Setteur de puce
	 *
	 *  Methode qui permet d'attribuer une puce a la case
	 *
	 *  \param pupuce : pointeur de la puce qu'on veut attribuer a la case
	 */
	void set_puce(Puce* pupuce);

	/*!
	 *  \brief Getteur de puce
	 *
	 *  Methode qui permet de connaitre la puce de la case
	 *
	 *  \return le pointeur de la puce
	 */
	Puce* get_puce();

	/*!
	 *  \brief Getteur de coordonnees de la case
	 *
	 *  Methode qui permet de connaitre les coordonnees de la case
	 *
	 *  \return les coordonnees de la case
	 */
	std::pair<int, int> get_pos();
};


#endif
