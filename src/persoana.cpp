#include "persoana.h"

persoana::persoana(string nume, string prenume)
{
    this->nume = nume;
    this->prenume = prenume;
}

void persoana::set_nume(string nume)
{
    if(nume.empty()) return;
    this->nume = nume;
}

void persoana::set_prenume(string prenume)
{
    if(prenume.empty()) return;
    this->prenume = prenume;
}
