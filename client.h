#ifndef CLIENT_H
#define CLIENT_H

#include <string>
using namespace std;

class client
{
    private:
        string nume;
        string prenume;
        int id;
    public:
        client(string nume = "", string prenume = "");
        string get_nume() {return nume;}
        string get_prenume() {return prenume;}
        int get_id() {return id;}

        void set_nume(const string nume);
        void set_prenume(const string prenume);
        
        ~client(){}
};

#endif //CLIENT_H