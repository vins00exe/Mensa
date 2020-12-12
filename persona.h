#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <iostream>
using namespace std;

class Persona {

public:
    Persona() {}
    Persona(string cf, string n, string c) : codiceFiscale(cf), nome(n), cognome(c) {}
    virtual ~Persona() {}

    virtual Persona* clone() const { return new Persona(*this); }

    virtual float Sconto() const {
        return 7;
    }

    void setCodiceFiscale(string cf) { codiceFiscale = cf; }
    void setNome(string n) { nome = n; }
    void setCognome(string c) { cognome = c; }

    string getCodiceFiscale() const { return codiceFiscale; }
    string getNome() const { return nome; }
    string getCognome() const { return cognome; }

    virtual void stampa() const { cout << codiceFiscale << " " << nome << " " << cognome; }

private:
    string codiceFiscale;
    string nome;
    string cognome;
};

#endif