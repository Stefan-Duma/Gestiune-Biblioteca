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

        void find_client(uint id);
        void find_book(uint id);
        
        ~admin(){}
};

#endif //ADMIN_H