#ifndef CARTE_H
#define CARTE_H

#include <string>
using namespace std;

class carte
{
    private:
        string nume;
        string autor;
        uint pret;
        uint numar_pagini;
    public:    
        carte(string nume = "", string autor = "", uint pret = 0, uint numar_pagini = 0);
        
        string get_nume() {return this->nume;}
        string get_autor() {return this->autor;}
        uint get_pret() {return this->pret;}
        uint get_numar_pagini() {return this->numar_pagini;}

        void set_nume(const string nume);
        void set_autor(const string autor);
        void set_pret(const uint pret);
        void set_numar_pagini(const uint numar_pagini);

        ~carte();
};

#endif //CARTE_H