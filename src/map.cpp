#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "map.h"


Map::Map(int size, int nb_puces, Chien* toutou) {
	taille = size;
	puces = nb_puces;
	medor = toutou;
}


Map::~Map() {
}


/* Initialize map */
void Map::init() {

	/* Init map size */
	carte.resize(taille*taille);

	/* Init map content */
	for (int i = 0; i < taille; i++) {
		for(int j = 0; j < taille; j++) {

			/* Define aura of a case */
			int aura = 0;

			if(j > medor->get_pos().first - 3 && j < medor->get_pos().first + 3
						&& i > medor->get_pos().second - 3 && i < medor->get_pos().second + 3) {
					aura = give_aura(i, j);
			}

			/* Init case */
			if(j == medor->get_pos().first && i == medor->get_pos().second) {
				carte.at(i*taille+j) = new Case(j, i, 3, medor);
				case_chien = i*taille+j;
			} else {
				carte.at(i*taille+j) = new Case(j, i, aura);
			}
		}
	}
}


/* Calcul case aura with dog position */
int Map::give_aura(int i, int j) {
	int aura = 0;

	if((j-medor->get_pos().first)*(j-medor->get_pos().first) > (i-medor->get_pos().second)*(i-medor->get_pos().second)) {
		aura = j-medor->get_pos().first;
	} else {
		aura = i-medor->get_pos().second;
	}

	if(aura < 0) {
		aura *= (-1);
	}

	return 3 - aura;
}


int Map::place_puce(Puce* pupuce) {

	pthread_mutex_lock(&mutmut);

	int tmp;

	do {
		tmp = rand()%(taille*taille);
	} while(!carte.at(tmp)->is_no_puce() || !carte.at(tmp)->is_no_dog());

	carte.at(tmp)->set_puce(pupuce);

	pthread_mutex_unlock(&mutmut);

	return tmp;
}


/* Threads handler */
void Map::get_threads() {
	int rc;
	pthread_t puce_thread[puces];

	/* Create thread */
	for(int i = 0; i < puces; i++) {

		rc = pthread_create(&puce_thread[i], NULL, work_thread, (void*) this);

		if(rc) {
			std::cerr << "Error : unable to create thread " << rc << std::endl;
			exit(-1);
		}
	}
}


/* Action in thread */
void* Map::work_thread(void* arg) {
	Map* tmp = (Map *) arg;
	unsigned int tps_milli = 150;
	int new_case;

	/* Create a puce */
	Puce* pupuce = new Puce();
	int pos_puce = tmp->place_puce(pupuce);

	/* Move and search for the dog */
	while(pos_puce != tmp->get_case_chien()) {

		Case* case_puce = tmp->get_case(pos_puce);
		std::pair<int, int> new_pos_puce = case_puce->get_puce()->move();
		new_case = (tmp->get_case(pos_puce)->get_pos().second + new_pos_puce.second) * tmp->get_size() +
					(tmp->get_case(pos_puce)->get_pos().first + new_pos_puce.first);

		/* Test si la case existe */
		if(new_case >= 0 && new_case < (tmp->get_size() * tmp->get_size())) {

			/* Test si la case est atteignable */
			if(tmp->get_case(new_case)->get_pos().first == tmp->get_case(pos_puce)->get_pos().first
					|| tmp->get_case(new_case)->get_pos().second == tmp->get_case(pos_puce)->get_pos().second) {

				/* Test occupation et aura de la case */
				if(tmp->get_case(new_case)->is_no_puce() && tmp->get_case(new_case)->get_aura() >= case_puce->get_aura()) {

					tmp->get_case(pos_puce)->set_puce(NULL);
					tmp->get_case(new_case)->set_puce(pupuce);
					pos_puce = new_case;
				}
			}
		}
		usleep(tps_milli * 1000);
	}

	tmp->carte.at(pos_puce)->set_puce(NULL);
	delete pupuce;

	pthread_exit(NULL);
}


Case* Map::get_case(int position) {
	return carte.at(position);
}


int Map::get_case_chien() {
	return case_chien;
}


int Map::get_size() {
	return taille;
}
