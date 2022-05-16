#include "Colectie.h"
#include "IteratorColectie.h"
#include <exception>
#include <iostream>
#include <math.h>

using namespace std;

// Teta(1)
//functia care da <hashCode>-ul unui element
int hashCode(TElem e) {
	//ptr moment numarul e intreg
	return abs(e);
}

// Teta(1)
//functia de dispersie
int Colectie::d(TElem x) const
{
	//dispersia prin diviziune
	return hashCode(x) % m;
}

/// caz favoranil : Teta(1)
/// caz defavorabil : Teta(n)
/// caz mediu : Teta(n)
/// overall case : O(n)
// actualizare primLiber
void Colectie::actPrimLiber()
{
	primLiber++;
	while (primLiber < m && e[primLiber] != NULL_TELEM)
		primLiber++;
}

/// Teta(m)
Colectie::Colectie() {
	len = 0;
	m = MAX; //initializam m cu o valoare predefinita

	e = new TElem[m];
	urm = new int[m];

	//se initializeaza vectorii
	for (int i = 0; i < m; i++) {
		e[i] = NULL_TELEM; // consideram ca elementul e intreg
		urm[i] = -1;
	}
	//initializare primLIber
	primLiber = 0;
}

/// caz favoranil : Teta(1)
/// caz defavorabil : Teta(n)
/// caz mediu : Teta(n)
/// overall case : O(n)
void Colectie::adauga(TElem elem) {
	//locatia de dispersie a cheii
	int i = d(elem);

	if (e[i] == NULL_TELEM)	// pozitia este libera
	{
		e[i] = elem;	// adaugam elementul
		len++;
		if (i == primLiber)
			actPrimLiber();	// actualizam primLiber, daca este nevoie
		return;
	}

	int j = -1;	// j va retine pozitia precedenta lui i, pentru a putea reface inlantuirea
	// daca pozitia nu este libera
	while (i != -1)	// iteram pana gasim capatul inlantuirii
	{
		j = i;
		i = urm[i];
	}

	if (primLiber >= m)
		throw exception{ "Nu mai exista spatiu pentru adaugarea elementului!" }; //nu tratam depasirea tabelei

	// adaugam elementul
	e[primLiber] = elem;
	urm[j] = primLiber;
	actPrimLiber();
	len++;
}

/// caz favoranil : Teta(1)
/// caz defavorabil : Teta(n)
/// caz mediu : Teta(n)
/// overall case : O(n)
bool Colectie::sterge(TElem elem) {
	//locatia de dispersie a cheii
	int i = d(elem);

	if (e[i] == NULL_TELEM)	// pozitia este libera
		return false;

	int j = -1;	// j va retine pozitia precedenta lui i, pentru a putea reface inlantuirea
	// daca pozitia nu este libera

	while (i != -1 && e[i] != elem)
	{
		j = i;
		i = urm[i];
	}

	if (i == -1) // nu am gasit elementul
		return false;

	// altfel
	bool gata = false;
	int pp, p;
	do
	{
		pp = i, p = urm[i];
		while (p != -1 && d(e[p]) != i)
		{
			pp = p;
			p = urm[p];
		}

		if (p != -1)
		{
			e[i] = e[p];
			j = pp;
			i = p;
		}
		else
			gata = true;

	} while (!gata);

	if (j != -1)
		urm[j] = urm[i];
	e[i] = NULL_TELEM;
	//urm[i] = -1;

	if (primLiber > i)
		primLiber = i;

	len--;
	return true;
}

/// caz favoranil : Teta(1)
/// caz defavorabil : Teta(n)
/// caz mediu : Teta(n)
/// overall case : O(n)
bool Colectie::cauta(TElem elem) const {
	//locatia de dispersie a cheii
	int i = d(elem);

	if (e[i] == NULL_TELEM)	// pozitia este libera
		return false;

	int j = -1;	// j va retine pozitia precedenta lui i, pentru a putea reface inlantuirea
	// daca pozitia nu este libera
	while (i != -1)	// iteram pana gasim capatul inlantuirii
	{
		if (e[i] == elem)
			return true;
		j = i;
		i = urm[i];
	}

	return false;
}

/// caz favoranil : Teta(1)
/// caz defavorabil : Teta(n)
/// caz mediu : Teta(n)
/// overall case : O(n)
int Colectie::nrAparitii(TElem elem) const {
	//locatia de dispersie a cheii
	int i = d(elem);

	if (e[i] == NULL_TELEM)	// pozitia este libera
		return 0;

	int count = 0;
	int j = -1;	// j va retine pozitia precedenta lui i, pentru a putea reface inlantuirea
	// daca pozitia nu este libera
	while (i != -1)	// iteram pana gasim capatul inlantuirii
	{
		if (e[i] == elem)
			count++;
		j = i;
		i = urm[i];
	}

	return count;
}

// Teta(1)
int Colectie::dim() const {
	return len;
}

// Teta(1)
bool Colectie::vida() const {
	return len == 0;
}

// Teta(1)
IteratorColectie Colectie::iterator() const {
	return  IteratorColectie(*this);
}

// Teta(1)
Colectie::~Colectie() {
	delete[] e;
	delete[] urm;
}


