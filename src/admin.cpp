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


abonat admin::find_abonat(string info)
{
    for(int i = 0; i < (int)abonati.size(); i++)
    {
        if(info == to_string(abonati[i].get_id())) return abonati[i];
        if(info == (abonati[i].get_nume() + " " + abonati[i].get_prenume())) return abonati[i];
    }
    cin.ignore();
    throw exceptie("Abonat negasit!\n");
}

carte admin::find_book(string info)
{
    for(int i = 0; i < (int)books.size(); i++)
    {
        if( admin::str_to_upper(info) == admin::str_to_upper(books[i].get_isbn())) return books[i];
        if( admin::str_to_upper(info) == admin::str_to_upper(books[i].get_titlu())) return books[i];
        if( admin::str_to_upper(info) == admin::str_to_upper(books[i].get_autor())) return books[i];
    }
    throw exceptie("Carte negasita\n");
}

void admin::remove_abonat(string info)
{
    abonat a = admin::find_abonat(info);
    for(size_t i = 0; i < abonati.size(); i++)
    {
        if(a == abonati[i])
        {
            abonati.erase(abonati.begin() + i);
        }
    }
}

void admin::remove_book(string info)
{
    carte c = admin::find_book(info);
    for(size_t i = 0; i < books.size(); i++)
    {
        if(c == books[i])
        {
            books.erase(books.begin() + i);
        }
    }
}