#include "meniu_abonati.h"
#include "button.h"
#include <SFML/Graphics.hpp>
#include <iostream>

void open_meniu_carti() {
    // Fereastra 2
    sf::RenderWindow window(sf::VideoMode(800, 600), "Optiuni abonati");

    Button add_abonat = Button(default_param(0), "Adauga abonat");
    Button exit = Button(default_param(1), "Exit");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                {window.close();}
                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) 
                {
                    if(add_abonat.isClicked(sf::Mouse::getPosition(window)))
                    {
                        window.close();
                    }
                    if(exit.isClicked(sf::Mouse::getPosition(window)))
                    {
                        window.close();
                    }
                }
        window.clear(sf::Color(51, 51, 51));
        add_abonat.draw(window);
        exit.draw(window);
        window.display();
    }
}
}
