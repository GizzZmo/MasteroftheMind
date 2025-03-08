#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>

class Game {
public:
    Game(int codeLength, int numColors);
    void reset();
    bool handleGuess(const std::vector<int>& guess, int& correctPosition, int& correctColor);
    void handlePlayerInput(const sf::Event& event);
    void draw(sf::RenderWindow& window);

private:
    int codeLength;
    int numColors;
    std::vector<int> secretCode;
    std::vector<std::vector<int>> guesses;

    void generateSecretCode();
};

#endif // GAME_H
