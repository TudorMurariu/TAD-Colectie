#pragma once

#define NULL_TELEM -80000
typedef int TElem;
#define MAX 3000022

class IteratorColectie;

class Colectie
{
	friend class IteratorColectie;

private:
	
	//reprezentare folosind o TD - rezolvare coliziuni prin liste intrepatrunse
	int m; //numarul de locatii din tabela de dispersie
	TElem* e; //vectorul elementelor
	int* urm; //vectorul legaturilor
	int primLiber; // locatia primei pozitii libere din tabela

	int len;

	// actualizare primLiber
	void actPrimLiber();
	//functia de dispersie
	int d(TElem x) const;

public:
		//constructorul implicit
		Colectie();

		//adauga un element in colectie
		void adauga(TElem e);

		//sterge o aparitie a unui element din colectie
		//returneaza adevarat daca s-a putut sterge
		bool sterge(TElem e);

		//verifica daca un element se afla in colectie
		bool cauta(TElem elem) const;

		//returneaza numar de aparitii ale unui element in colectie
		int nrAparitii(TElem elem) const;


		//intoarce numarul de elemente din colectie;
		int dim() const;

		//verifica daca colectia e vida;
		bool vida() const;

		//returneaza un iterator pe colectie
		IteratorColectie iterator() const;

		// destructorul colectiei
		~Colectie();

};

