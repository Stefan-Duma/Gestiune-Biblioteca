#include <iostream>
#include <SFML/Graphics.hpp>
#include "lib/Gui.hpp"
#include "lib/TextBox.hpp"
#include <GL/gl.h>
void add_TextBox(gui::Menu* menu)
{
    gui::TextBox* text = new gui::TextBox(100.0);
     (*menu).add(text);
}

int main()
{
    sf::RenderWindow app(sf::VideoMode(400, 300), "SFML Widgets", sf::Style::Close);

    gui::Menu menu(app);

    gui::Theme::loadFont("img/tahoma.ttf");
    gui::Theme::loadTexture("img/texture-default.png");

    gui::Button* add_book = new gui::Button("Adauga carte");
    gui::Button* add_client = new gui::Button("Adauga client");
    gui::Button* rent_book = new gui::Button("Inchiriaza carte");

    menu.add(add_book);
    menu.add(add_client);
    menu.add(rent_book);

    add_book->setCallback([&menu] {
        add_TextBox(&menu);
    });


    while (app.isOpen())
    {
        sf::Event event;
        while (app.pollEvent(event))
        {

            menu.onEvent(event);

            if (event.type == sf::Event::Closed)
                app.close();
        }

        app.clear(gui::Theme::windowBgColor);

        app.draw(menu);

        app.display();
    }
    return 0;
}
