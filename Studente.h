#ifndef STUDENTE_H
#define STUDENTE_H

#include "Persona.h"

class Studente : public Persona {

public:
    Studente() : Persona(), stipendio(0.0) {}
    Studente(string cf, string n, string c, float is) : Persona(cf, n, c), stipendio(is) {}
    float Sconto() const {
        if (stipendio <= 10000) {
            return 0.0;
        }
        else if (stipendio > 10000 && stipendio <= 20000) {
            return 2.0;
        }
        else if (stipendio > 20000 && stipendio <= 40000) {
            return 3.0;
        }
        else {
            return 4.0;
        }
    }

    Studente* clone() const { return new Studente(*this); }

    float getIsee() const { return stipendio; }
    void setIsee(float is) { stipendio = is; }

    void stampa() const { Persona::stampa(); cout << " - isee: " << stipendio << endl; }

private:
    float stipendio;
};

#endif