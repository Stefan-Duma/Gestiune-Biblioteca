#include "carte.h"

carte::carte(string nume_carte, string autor, uint pret, uint numar_pagini)
{
    static uint next_id = 0;
    this->nume_carte = nume_carte;
    this->autor = autor;
    this->pret = pret;
    this->numar_pagini = numar_pagini;
    this->id = next_id++;
}

carte::carte(array<string, 5> arr)
{
    id = (uint)atoi(arr[0].c_str());
    nume_carte = arr[1];
    autor = arr[2];
    pret = (uint) atoi(arr[3].c_str());
    numar_pagini = (uint)atoi(arr[4].c_str());
}

string carte::carte_to_file()
{
    return to_string(id) + sep + nume_carte + sep + autor +
           sep + to_string(pret) + sep + to_string(numar_pagini) + sep + '\n';

}

void carte::set_nume_carte(string nume_carte)
{
    if(nume_carte.empty()) return;
    this->nume_carte = nume_carte;
}

void carte::set_pret(uint pret)
{
    this->pret = pret;
}

void carte::set_numar_pagini(uint numar_pagini)
{
    this->numar_pagini = numar_pagini;
}
