#include "admin.h"
#include "exceptie.h"

string admin::str_to_upper(string str)
{
    string out = "";
    for(char ch: str)
    {
        out += toupper(ch);
    }
    return out;
}

abonat admin::find_abonat(uint id)
{
    for(int i = 0; i < (int)abonati.size(); i++)
    {
        if(id == abonati[i].get_id()) return abonati[i];
    }
    throw exceptie("Abonat negasit!\n");
}

abonat admin::find_abonat(string nume, string prenume)
{
    for(int i = 0; i < (int)abonati.size(); i++)
    {
        if( admin::str_to_upper(nume) == admin::str_to_upper(abonati[i].get_nume()) && 
        admin::str_to_upper(prenume) == admin::str_to_upper(abonati[i].get_prenume())) return abonati[i];
    }
    cin.ignore();
    throw exceptie("Abonat negasit!\n");
}

carte admin::find_book(uint id)
{
    for(int i = 0; i < (int)books.size(); i++)
    {
        if(id == books[i].get_id()) return books[i];
    }
    throw exceptie("Carte negasita!\n");
}

carte admin::find_book(string info)
{
    for(int i = 0; i < (int)books.size(); i++)
    {
        if( admin::str_to_upper(info) == admin::str_to_upper(books[i].get_nume_carte())) return books[i];
        if( admin::str_to_upper(info) == admin::str_to_upper(books[i].get_autor())) return books[i];
    }
    throw exceptie("Carte negasita\n");
}