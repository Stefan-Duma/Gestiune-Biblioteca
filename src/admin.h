#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <vector>
#include "abonat.h"
#include "carte.h"

using namespace std;

class admin{
    protected:
        vector<abonat> abonati;
        vector<carte> books;
    public:
        admin(){}
        void add(abonat new_abonat) {abonati.push_back(new_abonat);}
        void add(carte new_book) {books.push_back(new_book);}

        abonat find_abonat(string nume, string prenume);
        abonat find_abonat(uint id);
        carte find_book(string autor);
        carte find_book(uint id);
        
        vector<abonat> get_abonati() {return abonati;}
        vector<carte> get_books() {return books;}
        
        uint get_last_book_id() {return books.back().get_id();}
        static string str_to_upper(string str);
        ~admin(){}
};

#endif //ADMIN_H