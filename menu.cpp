#include "Menu.h"

Menu::Menu() {
    font.loadFromFile("arial.ttf");
    title.setFont(font);
    title.setString("Mastermind");
    title.setCharacterSize(50);
    title.setPosition(300, 50);

    playOption.setFont(font);
    playOption.setString("1. Play Game");
    playOption.setCharacterSize(30);
    playOption.setPosition(300, 150);

    solverOption.setFont(font);
    solverOption.setString("2. Solver Mode");
    solverOption.setCharacterSize(30);
    solverOption.setPosition(300, 200);

    quitOption.setFont(font);
    quitOption.setString("3. Quit");
    quitOption.setCharacterSize(30);
    quitOption.setPosition(300, 250);
}

int Menu::handleInput(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Num1) {
            return 1;
        } else if (event.key.code == sf::Keyboard::Num2) {
            return 2;
        } else if (event.key.code == sf::Keyboard::Num3) {
            return 3;
        }
    }
    return 0;
}

void Menu::draw(sf::RenderWindow& window) {
    window.draw(title);
    window.draw(playOption);
    window.draw(solverOption);
    window.draw(quitOption);
}
