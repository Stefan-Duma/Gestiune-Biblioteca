#include "src/persoana.h"
#include "src/carte.h"
#include "src/abonat.h"
#include "src/admin.h"
#include "src/exceptie.h"
#include "src/admin_fisier.h"
#include "src/functii_consola.h"
#include <iostream>
using namespace std;

//TODO1: Implementat legatura dintre abonat si cartile imprumutate, folosind un fisier cu structura:
//id_abonat1: id_carte1, id_carte2, ...
//id_abonat2: id_carte1, id_carte2, ...

//TODO2: Rezolvat problema resetarii id-urilor.
int main()
{
    int optiune = 0;
    admin_fisier admin_biblioteca("abonati.txt", "carti.txt");
    abonat abonat_temporar;
    carte carte_temporara;
    string nume, prenume, info;
    while(1){
        try{
            system("clear");
            afisare_meniu();
            cin >> optiune;
            if(cin.fail())
            {
                cin.clear();
                while(getchar() != '\n');
                throw exceptie("Optiune invalida!");
            }
            switch (optiune) 
            {
                case 0:
                    cout << "Oprire program!\n";
                    return 0;
                case 1:
                    abonat_temporar = citire_consola_abonat();
                    cout << "Abonat citit cu succes!";
                    cin.ignore();
                    getchar();
                    break;
                case 2:
                    carte_temporara = citire_consola_carte();
                    cout << "Carte citita cu succes!";
                    getchar();
                    break;
                case 3:
                    admin_biblioteca.write(abonat_temporar);
                    cout << "Abonatul a fost salvat!";
                    cin.ignore();
                    getchar();
                    break;
                case 4:
                    admin_biblioteca.write(carte_temporara);
                    cout << "Cartea a fost salvata!";
                    cin.ignore();
                    getchar();
                    break;
                case 5:
                    if(admin_biblioteca.get_abonati().empty()) admin_biblioteca.read_all_readers();
                    afisare_abonati(admin_biblioteca);
                    cin.ignore();
                    getchar();
                    break;
                case 6:
                    if(admin_biblioteca.get_books().empty()) admin_biblioteca.read_all_books();
                    afisare_carti(admin_biblioteca);
                    cin.ignore();
                    getchar();
                    break;
                case 7:
                    cout << "Introduceti numele abonatului: ";
                    cin >> nume;
                    cout << "Introduceti prenumele abonatului: ";
                    cin >> prenume;
                    afisare_abonat(admin_biblioteca.find_abonat(nume, prenume));
                    cin.ignore();
                    getchar();
                    break;
                case 8:
                    cout << "Introduceti numele si prenumele autorului sau numele cartii: ";
                    cin.ignore();
                    getline(cin, info);
                    afisare_carte(admin_biblioteca.find_book(info));    
                    getchar();
                    break;
                default:
                    cout << "Optiune invalida";
                    cin.ignore();
                    getchar();
                    break;
            }
        }
        catch(const exceptie& e)
        {
            cerr << e.mesaj;
            getchar();
        }
    }
    return 0;
}
