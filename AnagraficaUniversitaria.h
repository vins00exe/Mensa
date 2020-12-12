#ifndef ANAGRAFICA_H
#define ANAGRAFICA_H

#include <list>
using namespace std;

#include "Persona.h"
#include "Professore.h"
#include "Studente.h"

class Anagrafica {

public:
    Anagrafica() {}

    //Aggiunge uno studente
    void aggiungiStudente(string cf, string n, string c, float isee) {
        if (getPersona(cf) == nullptr) {
            Studente* s = new Studente(cf, n, c, isee);
            persone.push_back(s);
        }
    }

    //Aggiunge un professore
    void aggiungiProfessore(string cf, string n, string c, float stipendio) {
        if (getPersona(cf) == nullptr) {
            Professore* p = new Professore(cf, n, c, stipendio);
            persone.push_back(p);
        }
    }

    //Restituisce la persona se esiste una persona con quel codice fiscale, altrimenti restituisce nullptr
    Persona* getPersona(string cf) const {
        for (auto it = persone.begin(); it != persone.end(); it++) {
            Persona* p = *it;
            if (p->getCodiceFiscale() == cf)
                return p;
        }
        return nullptr;
    }

    void cancellaTutti() {
        for (auto p : persone) {
            delete p;
        }
        persone.clear();
    }

    ~Anagrafica() {
        cancellaTutti();
    }

    Anagrafica(const Anagrafica& a) {
        for (auto p : a.persone) {
            persone.push_back(p->clone());
        }
    }

    Anagrafica& operator=(const Anagrafica& a) {
        if (this != &a) {
            cancellaTutti();
            for (auto p : a.persone) {
                persone.push_back(p->clone());
            }
        }
        return *this;
    }

private:
    list<Persona*> persone;
};

#endif