/**
 * \file main.cpp
 * \brief Multithread et gtk.
 * \author ROTA - NICOLLE
 * \date 4 decembre 2014
 *
 * Programme de Multithread puces cherchant chien.
 *
 */
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <gtkmm/main.h>
#include <gtkmm/window.h>
#include "display.h"


/**
 * \fn int main (int argc, char* argv[])
 * \brief Entrée du programme.
 *
 * \param argc : nombre d'arguments du programme
 * \param argv : tableau d'arguments du programme (dimension de la map et nombre de puces)
 *
 * \return EXIT_SUCCESS - Arrêt normal du programme.
 */
int main(int argc, char* argv[]) {
	int taille = 20;
	int puces = ((taille * taille)/100)*10;
	int pixels_case = 10;

	/**
	 *  Program arguments handler */
	if (!(argv[1]) || !(argc > 2)) {
		std::cout << "Ce programme necessite des parametres:" << std::endl;
		std::cout << "- la taille de la carte" << std::endl;
		std::cout << "- le nombre de puces" << std::endl << std::endl;
		std::cout << "Prise en compte des parametres par defaut." << std::endl;
	} else {
		int tmp1 = atoi(argv[1]);
		int tmp2 = atoi(argv[2]);

		if(tmp1 < 20) {
			std::cout << "La carte est trop petite. Prise en compte des parametres par defaut." << std::endl;
		} else if(tmp1 > 70) {
			std::cout << "La carte est trop grande. Prise en compte des parametres par defaut." << std::endl;
		} else if(tmp2 < ((tmp1 * tmp1)/100)*10) {
			std::cout << "Nombre de puces insuffisant. Prise en compte des parametres par defaut." << std::endl;
		} else if(tmp2 > (tmp1 * tmp1)-1) {
			std::cout << "Puces trop nombreuses. Prise en compte des parametres par defaut." << std::endl;
		} else {
			taille = tmp1;
			puces = tmp2;
		}
	}

	std::cout << "taille de la carte: " << taille << "x" << taille << std::endl;
	std::cout << "nb de puces: " << puces << std::endl << std::endl;


	/**
	 *  Initialize dog and map */
	Chien* toutou = new Chien(taille);
	Map* carte = new Map(taille, puces, toutou);
	carte->init();


	/**
	 	 * Initialize window
	 */
	Gtk::Main kit(NULL, NULL);

	Gtk::Window win;
	win.set_title("Puces et Chien");


	/* Initialize scene */
	Display* scene = new Display(carte);
	scene->set_size_request(taille * pixels_case, taille * pixels_case);


	/* Start moving puces */
	carte->get_threads();


	/* Display scene in window */
	win.add(*scene);
	scene->show();
	Gtk::Main::run(win);


	/**
	 *  Delete objects */
	delete scene;
	delete carte;
	delete toutou;

	return EXIT_SUCCESS;
}
