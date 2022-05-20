#include <SFML/Graphics.hpp>
#include <string>

#include "FileRead.h"

using namespace std;
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(), "Alphabet-DROWLER", Style::Fullscreen | Style::Titlebar);

    Image icon; icon.loadFromFile("texture/icon.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    bool FullScreen = true;

    Texture background; background.loadFromFile("texture/background.jpg");
    Sprite Background; Background.setTexture(background);
    Background.setScale(
        window.getSize().x / Background.getGlobalBounds().width,
        window.getSize().y / Background.getGlobalBounds().height);

    Font font;                           font.loadFromFile("font/font.ttf");
    Text text;                           text.setFont(font);
    text.setCharacterSize(82);       text.setFillColor(Color::Black);
    text.setPosition(25, 55);        

    while (window.isOpen())
    {
        text.setString(Read());
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }window.clear();

        if (event.key.code == Keyboard::Escape)
            window.close();

        if (event.key.code == Keyboard::Tab)
        {
            if (!FullScreen) {
                window.create(VideoMode(), "Alphabet-DROWLER", Style::Fullscreen | Style::Titlebar);
                window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
                FullScreen = true;
            }
            else {
                window.create(VideoMode(1366, 768), "Alphabet-DROWLER", Style::Default);
                window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
                FullScreen = false;
            }
        }

        window.draw(Background);

        window.draw(text);

        window.display();
    }
}

//Author: IPOleksenko