#include "meniu_abonati.h"
#include "button.h"
#include "text_input.h"
#include "../src/abonat.h"
#include "../src/functii.h"
#include <SFML/Graphics.hpp>
#include <iostream>

void open_meniu_abonati() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Optiuni abonati");
    sf::Font font; 
    font.loadFromFile("gui/Arial.ttf");

    // Butoane
    Button add_abonat = Button(default_param(0), "Adauga abonat");
    Button view_abonat = Button(default_param(1), "View abonat");
    Button exit = Button(default_param(2), "Exit");
    
    // Câmpuri de text
    std::vector<text_input> prompt;
    prompt.push_back(text_input(sf::Vector2f(300, 50), sf::Vector2f(200, 30), font, 20, "Nume"));
    prompt.push_back(text_input(sf::Vector2f(300, 120), sf::Vector2f(200, 30), font, 20, "Prenume"));
    prompt.push_back(text_input(sf::Vector2f(300, 190), sf::Vector2f(200, 30), font, 20, "CNP"));
    prompt.push_back(text_input(sf::Vector2f(300, 260), sf::Vector2f(200, 30), font, 20, "Loc Nastere"));
    prompt.push_back(text_input(sf::Vector2f(300, 330), sf::Vector2f(200, 30), font, 20, "Telefon"));
    prompt.push_back(text_input(sf::Vector2f(300, 400), sf::Vector2f(200, 30), font, 20, "Email"));

    Button submitButton(sf::Vector2f(300, 500), sf::Vector2f(200, 50), sf::Color::Green, "Submit");
    
    bool showPrompt = false;
    bool showAbonat = false;
    abonat newAbonat; 
    
    // Resetăm focusul pentru câmpurile de text
    for (auto& input : prompt) {
        input.setFocus(false);
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Tratarea click-urilor pe butoane
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                if (add_abonat.isClicked(sf::Mouse::getPosition(window))) {
                    showAbonat = false;
                    showPrompt = true;
                }
                if(view_abonat.isClicked(sf::Mouse::getPosition(window))){
                    showAbonat = true;
                    showPrompt = false;
                }
                if (exit.isClicked(sf::Mouse::getPosition(window))) {
                    window.close();
                }
                // Verificăm dacă butonul de submit a fost apăsat
                if (submitButton.isClicked(sf::Mouse::getPosition(window))) {
                    newAbonat.set_nume(prompt[0].getText());
                    newAbonat.set_prenume(prompt[1].getText());
                    newAbonat.set_cnp(prompt[2].getText());
                    newAbonat.set_loc_nastere(stringToJudet(prompt[3].getText()));
                    newAbonat.set_telefon(prompt[4].getText());
                    newAbonat.set_email(prompt[5].getText());
                    for(auto& tx: prompt) tx.setText("");
                    std::cout << "Abonat adaugat!" << std::endl;
                    showPrompt = false;
                }

                // Verificăm pe care câmp de text am dat click
                bool anyInputFocused = false;
                for (auto& input : prompt) {
                    if (input.isMouseOver(sf::Mouse::getPosition(window))) {
                        input.setFocus(true); // Setăm focusul pe câmpul selectat
                        anyInputFocused = true;
                    } else {
                        input.setFocus(false); // Resetăm focusul pentru restul
                    }
                }

                // Dacă nu am dat click pe niciun câmp de text, resetăm focusul
                if (!anyInputFocused) {
                    for (auto& input : prompt) {
                        input.setFocus(false);
                    }
                }
            }

            // Procesăm evenimentele pentru fiecare câmp de text
            for (auto& input : prompt) {
                input.handleEvent(event);
            }

            
        }

        window.clear(sf::Color(51, 51, 51));

        // Desenăm butoanele
        add_abonat.draw(window);
        view_abonat.draw(window);
        exit.draw(window);

        // Desenăm câmpurile de text doar dacă promptul este activ
        if (showPrompt) {
            for (text_input& tx : prompt) {
                tx.draw(window);
                submitButton.draw(window);
            }
        }
        if(showAbonat)
        {
            afisare_abonat(window, font, newAbonat);
        }

        window.display();
    }
}
