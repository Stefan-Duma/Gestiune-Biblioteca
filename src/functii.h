#ifndef FUNCTII_H
#define FUNCTII_H
#include <SFML/Graphics.hpp>

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

int calculeazaCifraControl(const string& cnp);
string genereazaCNP(char sex, int an, Luna luna, int zi, int codJudet);
bool comparaCNPuri(const string& cnp1, const string& cnp2);


//Functii pentru interfata grafica
void afisare_abonat(sf::RenderWindow& window, sf::Font& font, abonat& a);

string str_to_upper(string str);
#endif //FUNCTII_CONSOLA_H