#include <stdlib.h>
#include <time.h>
#include "chien.h"


Chien::Chien(int taille) {
	srand(time(NULL));

	pos.first = rand()%taille;
	pos.second = rand()%taille;
}


Chien::~Chien() {
}


std::pair<int, int> Chien::get_pos() {
	return pos;
}
