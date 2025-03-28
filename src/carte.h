#ifndef CARTE_H
#define CARTE_H

#include "persoana.h"
#include <string>
#include <array>
using namespace std;

class carte
{
    private:
        char sep = ';';
        string nume_carte;
        string autor;
        uint pret;
        uint numar_pagini;
        uint id;
    public:    
        carte(){}
        carte(string nume_carte, string autor, uint pret, uint numar_pagini);
        carte(array<string, 5> linieFiseir);
        string get_nume_carte() {return this->nume_carte;}
        string get_autor() {return this->autor;}
        uint get_pret() {return this->pret;}
        uint get_numar_pagini() {return this->numar_pagini;}
        uint get_id() {return this->id;}

        void set_nume_carte(string nume);
        void set_autor(string autor) {this->autor = autor;}
        void set_pret(uint pret);
        void set_numar_pagini(const uint numar_pagini);

        string carte_to_file();
        ~carte(){}

        friend class persoana;
};

#endif //CARTE_H