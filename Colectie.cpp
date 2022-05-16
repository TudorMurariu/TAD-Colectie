#include "Colectie.h"
#include "IteratorColectie.h"
#include <exception>
#include <iostream>
#include <math.h>

using namespace std;

//functia care da <hashCode>-ul unui element
int hashCode(TElem e) {
	//ptr moment numarul e intreg
	return abs(e);
}

//functia de dispersie
int Colectie::d(TElem x) {
	//dispersia prin diviziune
	return hashCode(x) % m;
}

// actualizare primLiber
void Colectie::actPrimLiber()
{
	primLiber++;
	while (primLiber < m && e[primLiber] != -1)
		primLiber++;
}

Colectie::Colectie() {
	m = MAX; //initializam m cu o valoare predefinita
	//se initializeaza vectorii
	for (int i = 0; i < m; i++) {
		e[i] = -1; // consideram ca elementul e intreg
		urm[i] = -1;
	}
	//initializare primLIber
	primLiber = 0;
}


void Colectie::adauga(TElem elem) {
	
}


bool Colectie::sterge(TElem elem) {
	/* de adaugat */
	return false;
}


bool Colectie::cauta(TElem elem) const {
	/* de adaugat */
	return false;
}

int Colectie::nrAparitii(TElem elem) const {
	/* de adaugat */
	return 0;
}


int Colectie::dim() const {
	/* de adaugat */
	return 0;
}


bool Colectie::vida() const {
	/* de adaugat */
	return true;
}

IteratorColectie Colectie::iterator() const {
	return  IteratorColectie(*this);
}


Colectie::~Colectie() {
	/* de adaugat */
}


