#include <iostream>
#include "client.h"
#include "carte.h"
#include "persoana.h"
using namespace std;

int main()
{
    client alex("Alex", "Florin");
    client john("John", "Jameson");
    john.set_nume("Florian");
    cout << alex.get_nume() << endl <<  alex.get_prenume() << endl << alex.get_id() << endl;
    cout << john.get_nume() << endl << john.get_prenume() << endl << john.get_id() << endl;
    carte carte1("Crima si pedeapsa", {"John", "Doe"}, 120, 300);
    cout << carte1.get_autor() << carte1.get_numar_pagini() << carte1.get_nume_carte() << carte1.get_pret() << endl;
    return 0;
}