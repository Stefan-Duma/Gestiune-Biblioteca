#include <iostream>
#include <SFML/Graphics.hpp>
#include "../lib/Gui.hpp"
#include "../lib/TextBox.hpp"
#include "main_menu.h"
#include <GL/gl.h>
void add_TextBox(gui::Menu* menu)
{
    gui::TextBox* text = new gui::TextBox(100.0);
     (*menu).add(text);
}

int main()
{
    sf::RenderWindow app(sf::VideoMode(800, 600), "SFML Widgets", sf::Style::Close);

    gui::Menu menu(app);

    gui::Theme::loadFont("img/tahoma.ttf");
    gui::Theme::loadTexture("img/texture-default.png");

    main_menu mm;

    for(int i = 0; i < nr; i++) menu.add(mm[i]);

    gui::Button* close = new gui::Button("Exit");
    gui::Menu text_menu(app);
    
    
    text_menu.setPosition((sf::Vector2f){100.0, 200.0});
    
    bool draw = false;
    add_TextBox(&text_menu);
    text_menu.add(close);
    /*
    add_book->setCallback([&draw] {
        draw = true;
    });
*/
    close->setCallback([&draw] {
        draw = false;
    });
    while (app.isOpen())
    {
        sf::Event event;
        while (app.pollEvent(event))
        {

            menu.onEvent(event);
            text_menu.onEvent(event);
            if (event.type == sf::Event::Closed)
                app.close();
        }

        app.clear(gui::Theme::windowBgColor);
        app.draw(menu);
        if(draw == true) app.draw(text_menu);
        app.display();
    }
    return 0;
}
