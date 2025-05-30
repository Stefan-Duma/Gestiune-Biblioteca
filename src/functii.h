#ifndef FUNCTII_H
#define FUNCTII_H
#include <SFML/Graphics.hpp>
#include "../gui/text_input.h"
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

void update(vector<text_input> prompt, abonat& Abonat);
void update(vector<text_input> prompt, carte& Carte);

void get_info(vector<text_input> prompt, string& info);
void get_info_carte(vector<text_input> prompt, string& info);
//Functii pentru interfata grafica
void afisare_abonat(sf::RenderWindow& window, sf::Font& font, abonat& a);
void afisare_carte(sf::RenderWindow& window, sf::Font& font, carte& c);

string str_to_upper(string str);
#endif //FUNCTII_CONSOLA_H