#ifndef DISPLAY_H
#define DISPLAY_H

/*!
 * \file display.h
 * \brief gestion d'affichage de la map
 * \author ROTA - NICOLLE
 */

#include <gtkmm/drawingarea.h>
#include "map.h"

/*! \class Display
* \brief Affichage de la map
*
*  La classe gere le contenu et le rafraichissement de la fenetre d'affichage
*/
class Display : public Gtk::DrawingArea {
protected:
	Map* carte; /*!< Pointeur de la map*/

	/*!
	 *  \brief Gestion de contenu
	 *
	 *  Methode qui dessine les items
	 *
	 *  \param cr : reference graphique de la fenetre
	 *
	 *  \return true quand les changement ont ete realises
	 */
	virtual bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);

	/*!
	 *  \brief Gestion rafraichissement de la fenetre
	 *
	 *  Methode qui initialise le timer de rafraichissement de la fenetre
	 *
	 *  \return true quand le timer est initialise
	 */
	bool on_timeout();

public:
	/*!
	 *  \brief Constructeur
	 *
	 *  Constructeur de la classe Display
	 *
	 *  \param world : pointeur de la map
	 */
	Display(Map* world);

	/*!
	 *  \brief Destructeur
	 *
	 *  Destructeur de la classe Display
	 */
	virtual ~Display();
};


#endif
