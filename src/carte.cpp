#include "carte.h"

carte::carte(string nume_carte, const persoana& autor, uint pret, uint numar_pagini)
{
    this->nume_carte = nume_carte;
    this->autor = autor;
    this->pret = pret;
    this->numar_pagini = numar_pagini;
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

void carte::set_autor(const persoana autor)
{
    this->autor = autor;
}

void carte::set_pret(const uint pret)
{
    this->pret = pret;
}

void carte::set_numar_pagini(const uint numar_pagini)
{
    this->numar_pagini = numar_pagini;
}