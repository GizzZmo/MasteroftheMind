#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Menu.h"
#include "Solver.h"
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Mastermind with Solver");

    Menu menu;
    Game game(4, 6);
    Solver solver(4, 6);

    int menuChoice = 0;
    bool isPlaying = false;
    bool solverMode = false;

    std::vector<int> currentGuess(4, 0);
    size_t guessIndex = 0;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (!isPlaying) {
                menuChoice = menu.handleInput(event);
                if (menuChoice == 1) {
                    isPlaying = true;
                    solverMode = false;
                    game.reset();
                } else if (menuChoice == 2) {
                    isPlaying = true;
                    solverMode = true;
                    solver.reset();
                } else if (menuChoice == 3) {
                    window.close();
                }
            } else {
                if (solverMode) {
                    // Solver plays
                    static bool solved = false;
                    if (!solved) {
                        std::vector<int> guess = solver.makeGuess();
                        int correctPosition, correctColor;

                        if (game.handleGuess(guess, correctPosition, correctColor)) {
                            std::cout << "Solver cracked the code!" << std::endl;
                            solved = true;
                        } else {
                            solver.receiveFeedback(correctPosition, correctColor);
                        }
                    }
                } else {
                    // Player plays
                    if (event.type == sf::Event::KeyPressed) {
                        if (event.key.code == sf::Keyboard::Enter) {
                            int correctPosition, correctColor;
                            if (game.handleGuess(currentGuess, correctPosition, correctColor)) {
                                std::cout << "Congratulations! You cracked the code!\n";
                                isPlaying = false;
                            } else {
                                std::cout << "Feedback - Correct positions: " << correctPosition
                                          << ", Correct colors: " << correctColor << std::endl;
                            }
                        } else if (event.key.code >= sf::Keyboard::Num1 && event.key.code <= sf::Keyboard::Num6) {
                            currentGuess[guessIndex] = event.key.code - sf::Keyboard::Num1;
                            guessIndex = (guessIndex + 1) % currentGuess.size();
                        }
                    }
                }
            }
        }

        if (!isPlaying) {
            menu.draw(window);
        } else {
            window.clear(sf::Color::Black);
            game.draw(window);
            window.display();
        }
    }

    return 0;
}
