#ifndef PUCE_H
#define PUCE_H

/*!
 * \file puce.h
 * \brief proprietes d'une puce
 * \author ROTA - NICOLLE
 */

#include <utility>

/*! \class Puce
* \brief classe representant une puce
*
*  La classe gere les propriete d'une puce
*/
class Puce
{
public:
	/*!
	 *  \brief Constructeur
	 *
	 *  Constructeur de la classe Puce
	 */
	Puce();

	/*!
	 *  \brief Destructeur
	 *
	 *  Destructeur de la classe Puce
	 */
	~Puce();

	/*!
	 *  \brief Movement de la puce
	 *
	 *  Methode qui attribue aleatoirement la direction de deplacement de la puce
	 *
	 *  \return une pair direction / distance du deplacement de la puce
	 */
	std::pair<int, int> move();
};


#endif
