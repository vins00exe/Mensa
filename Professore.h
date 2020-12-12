#ifndef PROFESSORE_H
#define PROFESSORE_H

#include "Persona.h"

class Professore : public Persona {

public:
    Professore() : Persona(), stipendio(0.0) {}
    Professore(string cf, string n, string c, float s) : Persona(cf, n, c), stipendio(s) {}
    float Sconto() const {
        if (stipendio <= 30000) {
            return 2.5;
        }
        else if (stipendio > 30000 && stipendio <= 40000) {
            return 3.5;
        }
        else {
            return 5.0;
        }
    }

    Professore* clone() const { return new Professore(*this); }

    float getStipendio() const { return stipendio; }
    void setStipendio(float s) { stipendio = s; }

    void stampa() const { Persona::stampa(); cout << " - stipendio: " << stipendio << endl; }

private:
    float stipendio;
};

#endif