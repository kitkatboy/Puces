#ifndef CHIEN_H
#define CHIEN_H

/*!
 * \file chien.h
 * \brief proprietes du chien
 * \author ROTA - NICOLLE
 */

#include <utility>

/*! \class Chien
* \brief classe representant le chien
*
*  La classe gere les propriete du chien
*/
class Chien
{
protected:
	std::pair<int, int> pos; /*!< Coordonnees du chien*/

public:
	/*!
	 *  \brief Constructeur
	 *
	 *  Constructeur de la classe Chien
	 *
	 *  \param taille : dimension de la map
	 */
	Chien(int taille);

	/*!
	 *  \brief Destructeur
	 *
	 *  Destructeur de la classe Chien
	 */
	~Chien();

	/*!
	 *  \brief Getteur de coordonnees du chien
	 *
	 *  Methode qui permet de connaitre les coordonnees du chien
	 *
	 *  \return les coordonnees du chien
	 */
	std::pair<int, int> get_pos();
};


#endif
