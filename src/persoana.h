#ifndef PERSOANA_H
#define PERSOANA_H

#include <string>
using namespace std;

class persoana{
    
    public:
        string nume;
        string prenume;

        persoana(string nume = "", string prenume = "");
        string get_nume() {return nume;}
        string get_prenume() {return prenume;}
        
        void set_nume(string nume);
        void set_prenume(string prenume);
        void set_varsta(int varsta);
        ~persoana(){}
};

#endif //PERSOANA_H