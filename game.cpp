#include "Game.h"
#include <random>
#include <algorithm>
#include <iostream>

Game::Game(int codeLength, int numColors)
    : codeLength(codeLength), numColors(numColors) {
    reset();
}

void Game::reset() {
    generateSecretCode();
    guesses.clear();
}

void Game::generateSecretCode() {
    secretCode.resize(codeLength);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, numColors - 1);

    for (int& color : secretCode) {
        color = dist(gen);
    }
}

bool Game::handleGuess(const std::vector<int>& guess, int& correctPosition, int& correctColor) {
    correctPosition = 0;
    correctColor = 0;

    std::vector<int> codeCount(numColors, 0), guessCount(numColors, 0);

    for (int i = 0; i < codeLength; ++i) {
        if (guess[i] == secretCode[i]) {
            ++correctPosition;
        } else {
            ++codeCount[secretCode[i]];
            ++guessCount[guess[i]];
        }
    }

    for (int i = 0; i < numColors; ++i) {
        correctColor += std::min(codeCount[i], guessCount[i]);
    }

    guesses.push_back(guess);

    return correctPosition == codeLength;
}

void Game::handlePlayerInput(const sf::Event& event) {
    // Placeholder for player input handling
    std::cout << "Handle player input here.\n";
}

void Game::draw(sf::RenderWindow& window) {
    // Placeholder for rendering the game
    std::cout << "Render the game here.\n";
}
