#include "client.h"

client::client(string nume, string prenume) : persoana(nume, prenume)
{
    static int next_id = 0;
    this->id = next_id++;
}

void client::set_nume(const string nume)
{
    if(nume.empty()) return;
    this->nume = nume;
}

void client::set_prenume(const string prenume)
{
    if(prenume.empty()) return;
    this->prenume = prenume;
}

void client::set_id_carte(uint id_carte)
{
    this->id_carte = id_carte;
}