#ifndef CLIENT_H
#define CLIENT_H

#include "persoana.h"
#include <string>
using namespace std;

class client : public persoana
{
    private:
        uint id;
        uint id_carte;
    public:
        client(string nume, string prenume);
        string get_nume() {return nume;}
        string get_prenume() {return prenume;}
        uint get_id() {return id;}

        void set_nume(string nume);
        void set_prenume(string prenume);
        void set_id_carte(uint id_carte);
        ~client(){}
};

#endif //CLIENT_H