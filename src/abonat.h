#ifndef CITITOR_H
#define CITITOR_H

#include "persoana.h"
#include <string>
#include <array>

using namespace std;

class abonat : public persoana
{
    private:
        char sep = ';';
        uint id;
        string numar_telefon;
        string email;
        uint id_carte;
    public:
        abonat(){}
        abonat(string nume, string prenume, string nr_telefon, string email);
        abonat(array<string, 5> linieFisier);
        string get_nume() {return nume;}
        string get_prenume() {return prenume;}
        uint get_id() {return id;}
        uint get_id_carte() {return id_carte; }

        void set_nume(string nume);
        void set_prenume(string prenume);
        void set_id_carte(uint id_carte);
        void set_email(string email);
        void set_telefon(string nr_telefon);

        string abonat_to_file();
        ~abonat(){}
};

#endif //CITITOR_H