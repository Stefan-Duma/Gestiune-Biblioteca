#ifndef CARTE_H
#define CARTE_H

#include "persoana.h"
#include <string>
using namespace std;

class carte
{
    private:
        string nume_carte;
        persoana autor;
        uint pret;
        uint numar_pagini;
        uint id;
    public:    
        carte(string nume_carte = "", persoana autor = persoana(), uint pret = 0, uint numar_pagini = 0);
        
        string get_nume_carte() {return this->nume_carte;}
        string get_autor();
        uint get_pret() {return this->pret;}
        uint get_numar_pagini() {return this->numar_pagini;}
        uint get_id() {return this->id;}

        void set_nume_carte(const string nume);
        void set_autor(const persoana autor);
        void set_pret(const uint pret);
        void set_numar_pagini(const uint numar_pagini);

        ~carte(){}

        friend class persoana;
};

#endif //CARTE_H