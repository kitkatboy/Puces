#include "puce.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>


Puce::Puce() {
}


Puce::~Puce() {
}


/**
 *  Deplacement random puce
 *  \return direction du saut de la puce*/
std::pair<int, int> Puce::move() {
	std::pair<int, int> tmp;
	int d = rand()%6 - 3;

	if(rand()%2) {
		d *= (-1);
	}

	if(rand()%2) {
		tmp.first = 0;
		tmp.second = d;
	} else {
		tmp.first = d;
		tmp.second = 0;
	}

	return tmp;
}
