#ifndef FUNCTII_CONSOLA_H
#define FUNCTII_CONSOLA_H

#include "abonat.h"
#include "carte.h"
#include "admin.h"
#include "exceptie.h"
#include <iostream>
#include <string>
#include <array>

using namespace std;

void afisare_abonat(abonat c);
void afisare_carte(carte c);
void afisare_meniu();
void afisare_carti(admin& adm);
void afisare_abonati(admin& adm);
carte citire_consola_carte();
abonat citire_consola_abonat();

string str_to_upper(string str);
#endif //FUNCTII_CONSOLA_H