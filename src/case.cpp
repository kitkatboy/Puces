#include "case.h"


Case::Case(int x, int y, int odeur) {
	coord.first = x;
	coord.second = y;
	aura = odeur;
}


Case::Case(int x, int y, int odeur, Chien* toutou) {
	coord.first = x;
	coord.second = y;
	aura = odeur;
	medor = toutou;
}


/**
 *  Getteur de la valeur d'aura de la case
 *  \return aura de la case*/
int Case::get_aura() {
	int tmp;

	//pthread_mutex_lock(&mut);

	tmp = aura;

	//pthread_mutex_unlock(&mut);

	return tmp;
}


/**
 *  Setteur de la valeur d'aura de la case
 *  \param aura de la case*/
void Case::set_aura(int val) {
	aura = val;
}


/**
 *  Check si la case est occupee par une puce */
bool Case::is_no_puce() {
	bool tmp;

	pthread_mutex_lock(&mut);

	if(insecte == NULL) {
		tmp = true;
	} else {
		tmp = false;
	}

	pthread_mutex_unlock(&mut);

	return tmp;
}


/**
 *  Check si la case est occupee par le chien */
bool Case::is_no_dog() {
	bool tmp;

	pthread_mutex_lock(&mut);

	if(medor == NULL) {
		tmp = true;
	} else {
		tmp = false;
	}

	pthread_mutex_unlock(&mut);

	return tmp;
}


/**
 *  Setteur de puce sur case */
void Case::set_puce(Puce* pupuce) {
	pthread_mutex_lock(&mut);

	insecte = pupuce;

	pthread_mutex_unlock(&mut);
}


/* Getteur de puce sur case */
Puce* Case::get_puce() {
	Puce* tmp;

	//pthread_mutex_lock(&mut);

	tmp = insecte;

	//pthread_mutex_unlock(&mut);

	return tmp;
}


std::pair<int, int> Case::get_pos() {
	std::pair<int, int> tmp;

	//pthread_mutex_lock(&mut);

	tmp = coord;

	//pthread_mutex_unlock(&mut);

	return tmp;
}
