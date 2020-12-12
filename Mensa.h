#ifndef MENSA_H
#define MENSA_H
#include "AnagraficaUniversitaria.h"

class Mensa {
private:
	list<Persona*>l;

public:
	Mensa() {}
	void accesso(Persona* p);
	void stampa() const;
	float calcolaIncassoGiornaliero() const;
	void nuovoGiorno();

};

#endif
