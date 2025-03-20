#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <vector>
#include "client.h"
#include "carte.h"

using namespace std;

class admin{
    private:
        vector<client> clienti;
        vector<carte> carti;
    public:
        admin(){}
        void add(const client& client_nou) {clienti.push_back(client_nou);}
        void add(const carte& carte_noua) {carti.push_back(carte_noua);}

        client find_client(uint id);
        carte find_book(uint id);
        
        vector<client> get_clients() {return clienti;}
        vector<carte> get_books() {return carti;}
        ~admin(){}
};

#endif //ADMIN_H