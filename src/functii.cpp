#include "functii.h"
void afisare_abonat(sf::RenderWindow& window, sf::Font& font, abonat& a) {
    // Setăm textul pentru fiecare detaliu al abonatului
    sf::Text textNume, textPrenume, textCNP, textLocNastere, textTelefon, textEmail;
    
    // Setăm fontul și dimensiunea caracterului pentru toate textele
    textNume.setFont(font);
    textPrenume.setFont(font);
    textCNP.setFont(font);
    textLocNastere.setFont(font);
    textTelefon.setFont(font);
    textEmail.setFont(font);

    textNume.setCharacterSize(24);
    textPrenume.setCharacterSize(24);
    textCNP.setCharacterSize(24);
    textLocNastere.setCharacterSize(24);
    textTelefon.setCharacterSize(24);
    textEmail.setCharacterSize(24);

    // Setăm culorile textelor
    textNume.setFillColor(sf::Color::White);
    textPrenume.setFillColor(sf::Color::White);
    textCNP.setFillColor(sf::Color::White);
    textLocNastere.setFillColor(sf::Color::White);
    textTelefon.setFillColor(sf::Color::White);
    textEmail.setFillColor(sf::Color::White);

    // Setăm string-ul pentru fiecare text
    textNume.setString("Nume: " + a.get_nume());
    textPrenume.setString("Prenume: " + a.get_prenume());
    textCNP.setString("CNP: " + a.get_cnp());
    textLocNastere.setString("Locul Nasterii: " + judetToString(a.get_loc_nastere()));
    textTelefon.setString("Telefon: " + a.get_numar_telefon());
    textEmail.setString("Email: " + a.get_email());

    // Setăm pozițiile pentru fiecare text
    textNume.setPosition(300, 50);
    textPrenume.setPosition(300, 100);
    textCNP.setPosition(300, 150);
    textLocNastere.setPosition(300, 200);
    textTelefon.setPosition(300, 250);
    textEmail.setPosition(300, 300);

    // Desenăm textele pe fereastră
    window.draw(textNume);
    window.draw(textPrenume);
    window.draw(textCNP);
    window.draw(textLocNastere);
    window.draw(textTelefon);
    window.draw(textEmail);
}

void afisare_carte(sf::RenderWindow& window, sf::Font& font, carte& c) {
    // Creăm obiecte text pentru fiecare câmp
    sf::Text textTitlu, textAutor, textEditura, textPret, textPagini, textISBN;

    // Setăm fontul și dimensiunea textului
    textTitlu.setFont(font);
    textAutor.setFont(font);
    textEditura.setFont(font);
    textPret.setFont(font);
    textPagini.setFont(font);
    textISBN.setFont(font);

    textTitlu.setCharacterSize(24);
    textAutor.setCharacterSize(24);
    textEditura.setCharacterSize(24);
    textPret.setCharacterSize(24);
    textPagini.setCharacterSize(24);
    textISBN.setCharacterSize(24);

    // Setăm culoarea
    textTitlu.setFillColor(sf::Color::White);
    textAutor.setFillColor(sf::Color::White);
    textEditura.setFillColor(sf::Color::White);
    textPret.setFillColor(sf::Color::White);
    textPagini.setFillColor(sf::Color::White);
    textISBN.setFillColor(sf::Color::White);

    // Completăm conținutul textului
    textTitlu.setString("Titlu: " + c.get_titlu());
    textAutor.setString("Autor: " + c.get_autor());
    textEditura.setString("Editura: " + c.get_editura());
    textPret.setString("Pret: " + std::to_string(c.get_pret()) + " RON");
    textPagini.setString("Numar pagini: " + std::to_string(c.get_numar_pagini()));
    textISBN.setString("ISBN: " + c.get_isbn());

    // Poziționăm textele
    textTitlu.setPosition(300, 50);
    textAutor.setPosition(300, 100);
    textEditura.setPosition(300, 150);
    textPret.setPosition(300, 200);
    textPagini.setPosition(300, 250);
    textISBN.setPosition(300, 300);

    // Le desenăm
    window.draw(textTitlu);
    window.draw(textAutor);
    window.draw(textEditura);
    window.draw(textPret);
    window.draw(textPagini);
    window.draw(textISBN);
}


void update(vector<text_input> prompt, abonat& Abonat)
{
    for (size_t i = 0; i < prompt.size(); ++i) {
        if (prompt[i].getText() == "") {
            std::cout << "Câmpul " << i + 1 << " este gol!" << std::endl;
        } else {
            // Setează câmpul corespunzător în obiectul Abonat
            switch (i) {
                case 0:
                    Abonat.set_nume(prompt[i].getText());
                    break;
                case 1:
                    Abonat.set_prenume(prompt[i].getText());
                    break;
                case 2:
                    Abonat.set_cnp(prompt[i].getText());
                    break;
                case 3:
                    Abonat.set_loc_nastere(stringToJudet(prompt[i].getText()));
                    break;
                case 4:
                    Abonat.set_telefon(prompt[i].getText());
                    break;
                case 5:
                    Abonat.set_email(prompt[i].getText());
                    break;
                default:
                    break;
            }

        }
    }
}

void update(vector<text_input> prompt, carte& Carte)
{
    for (size_t i = 0; i < prompt.size(); ++i) {
        if (prompt[i].getText().empty()) {
            std::cout << "Câmpul " << i + 1 << " este gol!" << std::endl;
        } else {
            switch (i) {
                case 0:
                    Carte.set_titlu(prompt[i].getText());
                    break;
                case 1:
                    Carte.set_autor(prompt[i].getText());
                    break;
                case 2:
                    Carte.set_editura(prompt[i].getText());
                    break;
                case 3:
                    Carte.set_pret(static_cast<uint>(std::stoi(prompt[i].getText())));
                    break;
                case 4:
                    Carte.set_numar_pagini(static_cast<uint>(std::stoi(prompt[i].getText())));
                    break;
                default:
                    break;
            }
        }
    }
}

void get_info(vector<text_input> prompt, string& info)
{
    string nume, prenume, data;
    nume = prompt[0].getText();
    prenume = prompt[1].getText();
    if(nume != "" && prenume != "") {
        info = nume + ' ' + prenume;
    } else {
        for(size_t i = 2; i < prompt.size(); i++) {
            data = prompt[i].getText();
            if(data != "") info = data;
        }
    }
}

void get_info_carte(vector<text_input> prompt, string& info)
{
    for(const auto& tx: prompt)
    {
        if(tx.getText() != "") info = tx.getText();
    }
}
/*
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
    cout << "Nume carte: " << c.get_titlu() << endl;
    cout << "Autor: " << c.get_autor() << endl;
    cout << "Numar pagini: " << c.get_numar_pagini() << endl;
    cout << "Pret: " << c.get_pret() << " lei" << endl; 
}

void afisare_carti(admin& adm)
{
    for(carte& c: adm.get_books())
    {
        cout << endl;
        cout << "Nume carte: " << c.get_titlu() << endl;
        cout << "Autor: " << c.get_autor() << endl;
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
    return abonat(0, nume, prenume, telefon, email);
}

void afisare_abonati(admin& adm)
{
    for(abonat c: adm.get_abonati())
    {
        cout << endl;
        cout << "Nume abonat: " << c.get_nume() << endl;
        cout << "Prenume abonat: " << c.get_prenume() << endl;
        cout << "Id abonat: " << c.get_id() << endl;
    }
}

void afisare_abonat(abonat c)
{
        cout << endl;
        cout << "Nume abonat: " << c.get_nume() << endl;
        cout << "Prenume abonat: " << c.get_prenume() << endl;
        cout << "Id abonat: " << c.get_id() << endl;
}

*/
int calculeazaCifraControl(const string& cnp) {
    int coef[12] = {2, 7, 9, 1, 4, 6, 8, 5, 3, 7, 9, 1};  // Coeficientii pentru CNP
    int suma = 0;
    
    for (int i = 0; i < 12; ++i) {
        suma += (cnp[i] - '0') * coef[i];
    }
    
    return suma % 11 == 10 ? 1 : suma % 11;
}

// Functie pentru generarea unui CNP pe baza datei si locului nasterii
string genereazaCNP(char sex, int an, Luna luna, int zi, int codJudet) {
    string cnp = "";
    
    int s;
    if (an >= 1900 && an <= 1999) {
        s = (sex == 'M' || sex == 'm') ? 1 : 2;
    } else if (an >= 2000 && an <= 2099) {
        s = (sex == 'M' || sex == 'm') ? 5 : 6;
    } else {
        throw exceptie("Anul trebuie sa fie intre 1900 si 2099.");
    }

    cnp += to_string(s);
    // Adaugă anul nașterii (ultimele 2 cifre ale anului)
    cnp += to_string(an).substr(2, 2);  // Ultimele două cifre ale anului
    
    // Adaugă luna de naștere (cu 0 în față dacă este necesar)
    cnp += (luna < 10 ? "0" : "") + to_string(luna);
    
    // Adaugă ziua de naștere (cu 0 în față dacă este necesar)
    cnp += (zi < 10 ? "0" : "") + to_string(zi);
    
    // Adaugă codul județului (2 caractere)
    cnp += (codJudet < 10 ? "0" : "") + to_string(codJudet);
    
    // Adaugă un număr aleator pentru numărul de ordine (între 1 și 99)
    int numar = rand() % 100 + 1;
    cnp += (numar < 10 ? "0" : "") + to_string(numar);
    
    // Calculează cifra de control
    int cifraControl = calculeazaCifraControl(cnp);
    cnp += to_string(cifraControl);
    
    return cnp;
}

bool comparaCNPuri(const string& cnp1, const string& cnp2) {
    if (cnp1.length() < 9 || cnp2.length() < 9) {
        return false;
    }
    return cnp1.substr(0, 9) == cnp2.substr(0, 9);
}