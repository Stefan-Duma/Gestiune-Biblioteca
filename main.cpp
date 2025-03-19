#include <iostream>
#include "client.h"
#include "carte.h"
#include "persoana.h"
using namespace std;

int main()
{
    int optiune = 0;
    do{
        switch(toupper(optiune))
        {
            case 1: //Adauga carte
                break;
            case 2: //Adauga client
                break;
            case 3: //Afiseaza lista carti
                break;
            case 4: //Afiseaza lista clienti
                break;    
            case 5:
                break;    
            default:
                break;
        }
    }
    while(optiune != 0);
    
    return 0;
}