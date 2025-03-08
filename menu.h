#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>

class Menu {
public:
    Menu();
    int handleInput(const sf::Event& event);
    void draw(sf::RenderWindow& window);

private:
    sf::Font font;
    sf::Text title;
    sf::Text playOption;
    sf::Text solverOption;
    sf::Text quitOption;
};

#endif // MENU_H
