#include "meniu_carti.h"
#include "button.h"
#include "text_input.h"
#include "../src/carte.h"
#include "../src/admin_fisier.h"
#include "../src/functii.h"
#include <SFML/Graphics.hpp>
#include <iostream>

enum CarteMenuState {
    C_DEFAULT,
    C_ADD,
    C_SEARCH,
    C_EDIT,
    C_REMOVE,
    C_SHOW,
};

void open_meniu_carti() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Optiuni carti");
    sf::Font font;
    if (!font.loadFromFile("gui/Arial.ttf")) {
        std::cerr << "Eroare la incarcarea fontului.\n";
        return;
    }

    // Butoane
    Button add_book(default_param(0), "Adauga carte");
    Button find_book(default_param(1), "Cauta carte");
    Button modify_book(default_param(2), "Modifica carte");
    Button delete_book(default_param(3), "Elimina carte");
    Button exit(default_param(4), "Exit");

    // Campuri input
    std::vector<text_input> prompt;
    prompt.push_back(text_input(sf::Vector2f(300, 50), sf::Vector2f(200, 30), font, 20, "Titlu"));
    prompt.push_back(text_input(sf::Vector2f(300, 120), sf::Vector2f(200, 30), font, 20, "Autor"));
    prompt.push_back(text_input(sf::Vector2f(300, 190), sf::Vector2f(200, 30), font, 20, "Editura"));
    prompt.push_back(text_input(sf::Vector2f(300, 260), sf::Vector2f(200, 30), font, 20, "Pret"));
    prompt.push_back(text_input(sf::Vector2f(300, 330), sf::Vector2f(200, 30), font, 20, "Nr. pagini"));

    Button submitButton(sf::Vector2f(300, 500), sf::Vector2f(200, 50), sf::Color(0, 168, 107), "Submit");

    admin_fisier admin("info/abonati.txt", "info/carti.txt");
    admin.read_all_books();
    vector<carte> carti;
    carte Carte;
    string info;
    CarteMenuState stare = C_DEFAULT;

    for (auto& input : prompt)
        input.setFocus(false);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                if (add_book.isClicked(sf::Mouse::getPosition(window))) {
                    stare = C_ADD;
                    submitButton.setText("ADAUGA");
                }
                if (find_book.isClicked(sf::Mouse::getPosition(window))) {
                    stare = C_SEARCH;
                    submitButton.setText("CAUTA");
                }
                if (modify_book.isClicked(sf::Mouse::getPosition(window))) {
                    stare = C_EDIT;
                    submitButton.setText("SALVEAZA");
                }
                if (delete_book.isClicked(sf::Mouse::getPosition(window))) {
                    stare = C_REMOVE;
                    submitButton.setText("STERGE");
                }
                if (exit.isClicked(sf::Mouse::getPosition(window))) {
                    window.close();
                }

                if (submitButton.isClicked(sf::Mouse::getPosition(window))) {
                    switch (stare) {
                        case C_ADD:
                            Carte.set_titlu(prompt[0].getText());
                            Carte.set_autor(prompt[1].getText());
                            Carte.set_editura(prompt[2].getText());
                            Carte.set_pret(std::stoi(prompt[3].getText()));
                            Carte.set_numar_pagini(std::stoi(prompt[4].getText()));
                            Carte.set_isbn(carte::genereazaISBN());
                            for (auto& tx : prompt) tx.setText("");
                            std::cout << "Carte adaugata!\n";
                            admin.add(Carte);
                            admin.write(Carte);
                            stare = C_DEFAULT;
                            break;

                        case C_SEARCH:
                            get_info_carte(prompt, info);; // presupunem că titlul e folosit pentru căutare
                            Carte = admin.find_book(info);
                            for (auto& tx : prompt) tx.setText("");
                            stare = C_SHOW;
                            break;

                        case C_EDIT:
                            carti = admin.get_books();
                            for(size_t i = 0; i < carti.size(); i++)
                            {
                                if(carti[i] == Carte)
                                {
                                    update(prompt, carti[i]);
                                    admin.set_books(carti);
                                }
                            }
                            for (auto& tx : prompt) tx.setText("");
                            admin.write_all_books();
                            stare = C_DEFAULT;
                            break;

                        case C_REMOVE:
                            info = prompt[0].getText(); // din nou, după titlu
                            admin.remove_book(info);
                            for (auto& tx : prompt) tx.setText("");
                            admin.write_all_books();
                            stare = C_DEFAULT;
                            break;

                        default:
                            stare = C_DEFAULT;
                            break;
                    }
                }

                bool anyInputFocused = false;
                for (auto& input : prompt) {
                    if (input.isMouseOver(sf::Mouse::getPosition(window))) {
                        input.setFocus(true);
                        anyInputFocused = true;
                    } else {
                        input.setFocus(false);
                    }
                }

                if (!anyInputFocused) {
                    for (auto& input : prompt)
                        input.setFocus(false);
                }
            }

            for (auto& input : prompt)
                input.handleEvent(event);
        }

        window.clear(sf::Color(51, 51, 51));
        add_book.draw(window);
        find_book.draw(window);
        modify_book.draw(window);
        delete_book.draw(window);
        exit.draw(window);

        if (stare == C_ADD || stare == C_SEARCH || stare == C_EDIT || stare == C_REMOVE) {
            for (text_input& tx : prompt)
                tx.draw(window);
            submitButton.draw(window);
        }

        if (stare == C_SHOW) {
            afisare_carte(window, font, Carte); // trebuie să ai funcția implementată
        }

        window.display();
    }
}
