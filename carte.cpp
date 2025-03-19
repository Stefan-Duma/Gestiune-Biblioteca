#include "carte.h"

carte::carte(string nume_carte, persoana autor, uint pret, uint numar_pagini)
{
    static uint next_id = 0;
    this->nume_carte = nume_carte;
    this->autor = autor;
    this->pret = pret;
    this->numar_pagini = numar_pagini;
    this->id = next_id++;
}

string carte::get_autor()
{
    return "" + autor.get_nume() + " " + autor.get_prenume();
}

void carte::set_nume_carte(string nume_carte)
{
    if(nume_carte.empty()) return;
    this->nume_carte = nume_carte;
}

void carte::set_autor(persoana autor)
{
    this->autor = autor;
}

void carte::set_pret(uint pret)
{
    this->pret = pret;
}

void carte::set_numar_pagini(uint numar_pagini)
{
    this->numar_pagini = numar_pagini;
}