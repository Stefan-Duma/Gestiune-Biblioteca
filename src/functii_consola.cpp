#include "functii_consola.h"

void afisare_meniu()
{
    cout << "Meniu de optiuni:" << endl;
    cout << "1. Adauga abonat" << endl;
    cout << "2. Adauga carte" << endl;
    cout << "3. Salveaza abonat in fisier" << endl;
    cout << "4. Salveaza carte in fisier" << endl;
    cout << "5. Afiseaza abonati" << endl;
    cout << "6. Afiseaza carti" << endl;
    cout << "7. Cautare abonat" << endl;
    cout << "8. Cautare carte" << endl;
    cout << "0. Exit" << endl;
    cout << "Alege o optiune: ";
}

carte citire_consola_carte() {
    string nume, buffer;
    string autor;
    uint pret, numar_pagini;
    
    cout << "Introduceti numele cartii: ";
    cin.ignore();
    
    getline(cin, nume);
    
    cout << "Introduceti numele si prenumele autorului: ";
    getline(cin, autor);
    
    cout << "Introduceti pretul cartii: ";
    cin >> pret;

    if(cin.fail()) 
    {
        cin.clear();
        while(getchar() != '\n');
        throw exceptie("Valoarea pretului nu este valida!\n");
    }

    cout << "Introduceti numarul de pagini: ";
    cin >> numar_pagini;  
    
    if(cin.fail())
    {
        cin.clear();
        while(getchar() != '\n'); 
        throw exceptie("Numarul de pagini nu este valid!\n");
    }
    cin.ignore();
    return carte(nume, autor, pret, numar_pagini);
}

void afisare_carte(carte c)
{
    cout << endl;
    cout << "Nume carte: " << c.get_nume_carte() << endl;
    cout << "Autor: " << c.get_autor() << endl;
    cout << "ID: " << c.get_id() << endl;
    cout << "Numar pagini: " << c.get_numar_pagini() << endl;
    cout << "Pret: " << c.get_pret() << " lei" << endl; 
}

void afisare_carti(admin& adm)
{
    for(carte& c: adm.get_books())
    {
        cout << endl;
        cout << "Nume carte: " << c.get_nume_carte() << endl;
        cout << "Autor: " << c.get_autor() << endl;
        cout << "ID: " << c.get_id() << endl;
        cout << "Numar pagini: " << c.get_numar_pagini() << endl;
        cout << "Pret: " << c.get_pret() << " lei" << endl; 
    }
}

abonat citire_consola_abonat()
{
    string nume, prenume, email, telefon;
    cout << "Nume: ";
    cin >> nume;
    
    cout << "Prenume: ";
    cin >> prenume;

    cout << "Email: ";
    cin >> email;
    
    cout << "Numar de telefon: ";
    cin >> telefon;
    return abonat(nume, prenume, telefon, email);
}

void afisare_abonati(admin& adm)
{
    for(abonat c: adm.get_abonati())
    {
        cout << endl;
        cout << "Nume abonat: " << c.get_nume() << endl;
        cout << "Prenume abonat: " << c.get_prenume() << endl;
        cout << "Id abonat: " << c.get_id() << endl;
        cout << "Id carte inchiriata: " << c.get_id_carte() << endl;
    }
}

void afisare_abonat(abonat c)
{
        cout << endl;
        cout << "Nume abonat: " << c.get_nume() << endl;
        cout << "Prenume abonat: " << c.get_prenume() << endl;
        cout << "Id abonat: " << c.get_id() << endl;
        cout << "Id carte inchiriata: " << c.get_id_carte() << endl;
}