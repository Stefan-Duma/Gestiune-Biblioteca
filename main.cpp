#include <iostream>
#include "client.h"
#include "carte.h"
using namespace std;

int main()
{
    client alex("Alex", "Florin");
    client john("John", "Jameson");
    john.set_nume("Florian");
    cout << alex.get_nume() << endl <<  alex.get_prenume() << endl << alex.get_id() << endl;
    cout << john.get_nume() << endl << john.get_prenume() << endl << john.get_id() << endl;
    return 0;
}