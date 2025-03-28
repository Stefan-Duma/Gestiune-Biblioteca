#include "abonat.h"

abonat::abonat(string nume, string prenume, string nr_telefon, string email) : persoana(nume, prenume)
{
    static int next_id = 0;
    this->id = next_id++;
    this->numar_telefon = nr_telefon;
    this->email = email;
}

abonat::abonat(array<string, 5> arr)
{
    id = (uint)atoi(arr[0].c_str());
    nume = arr[1];
    prenume = arr[2];
    numar_telefon = arr[3];
    email = arr[4];
}

string abonat::abonat_to_file()
{
    return to_string(id) + sep + nume + sep + prenume + sep + numar_telefon +
           sep + email + sep + '\n';
}
void abonat::set_nume(const string nume)
{
    if(nume.empty()) return;
    this->nume = nume;
}

void abonat::set_prenume(const string prenume)
{
    if(prenume.empty()) return;
    this->prenume = prenume;
}

void abonat::set_id_carte(uint id_carte)
{
    this->id_carte = id_carte;
}

void abonat::set_email(const string email)
{
    if(email.empty()) return;
    this->email = email;
}

void abonat::set_telefon(const string nr_telefon)
{
    if(nr_telefon.empty()) return;
    this->numar_telefon = nr_telefon;
}