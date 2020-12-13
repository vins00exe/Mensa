#include "Mensa.h"


void Mensa::accesso(Persona* p) {
	l.push_back(p);
}

void Mensa::stampa() const {
	for (auto it = l.begin(); it != l.end(); ++it) {
		(*it)->stampa();
	}
}

//lo sconto lo calcolo in ogni classe, così se vengono aggiunte nuove figure che possono accedere alla mensa non c'è bisogno di toccare questa classe.
float Mensa::calcolaIncassoGiornaliero() const {
	float incasso = 0.0;
	for (auto it = l.begin(); it != l.end(); ++it) {
		incasso += (*it)->Sconto();
	}
	return incasso;
}

void Mensa::nuovoGiorno() {
	l.clear();
}
