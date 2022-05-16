#include "IteratorColectie.h"
#include "Colectie.h"
#include <exception>

using namespace std;

// Teta(1)
IteratorColectie::IteratorColectie(const Colectie& c): col(c) {
	i = 0;
}

/// caz favoranil : Teta(1)
/// caz defavorabil : Teta(n)
/// caz mediu : Teta(n)
/// overall case : O(n)
void IteratorColectie::prim() {
	i = 0;
	while (this->col.e[i] == -1 && i < this->col.m)
		++i;
}

/// caz favoranil : Teta(1)
/// caz defavorabil : Teta(n)
/// caz mediu : Teta(n)
/// overall case : O(n)
void IteratorColectie::urmator() {
	if (!valid())
		throw exception();
	
	++i;
	while (this->col.e[i] == NULL_TELEM && i < this->col.m)
		++i;
}

// Teta(1)
bool IteratorColectie::valid() const {
	return i >= 0 && i < this->col.m && this->col.e[i] != NULL_TELEM;
}


// Teta(1)
TElem IteratorColectie::element() const {
	if (!valid())
		throw exception();
	return this->col.e[i];
}
