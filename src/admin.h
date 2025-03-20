#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <vector>
#include "client.h"
#include "carte.h"

using namespace std;

class admin{
    private:
        vector<client> clients;
        vector<carte> books;
    public:
        admin(){}
        void add(const client& new_client) {clients.push_back(new_client);}
        void add(const carte& new_book) {books.push_back(new_book);}

        client find_client(uint id);
        carte find_book(uint id);
        
        vector<client> get_clients() {return clients;}
        vector<carte> get_books() {return books;}
        ~admin(){}
};

#endif //ADMIN_H