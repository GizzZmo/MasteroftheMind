# MasteroftheMind
Mastermind clone

Integrating Donald Knuth's Five-Guess Algorithm into the Mastermind game will allow the application to act as a codebreaker and efficiently solve the player's secret code. The algorithm systematically minimizes the possible solutions based on feedback from the guesses, making it a powerful choice for this application.

Here’s how to modify the existing code to add this feature:

---

### Updated Filstruktur
```
|-- Mastermind/
    |-- main.cpp
    |-- Game.h
    |-- Game.cpp
    |-- Menu.h
    |-- Menu.cpp
    |-- Solver.h
    |-- Solver.cpp
    |-- SFML/
    |-- arial.ttf
```

---
### Key Features Added:
1. **Solver Mode**:
   - Uses Donald Knuth's Five-Guess Algorithm to efficiently solve the player's secret code.
   - Runs automatically and provides feedback for each guess until the code is cracked.

2. **Two Game Modes**:
   - Player-plays mode: The player guesses the code.
   - Solver mode: The application solves the code set by the player.

3. **Interactive Feedback**:
   - Displays progress visually using polygons.

This implementation provides both a human-playable game and an automated code-solver using Knuth's algorithm. Let me know if you'd like additional features or enhancements! 😊

Here's a detailed README file for your Mastermind application:

---

# MasteroftheMind

MasteroftheMind is a modern implementation of the classic code-breaking game **Mastermind**. This application not only allows players to challenge themselves but also features a sophisticated **solver mode** powered by Donald Knuth's Five-Guess Algorithm. The solver acts as the codebreaker and efficiently cracks the player's secret code. Built with **SFML**, this game brings together interactivity and powerful logic in one engaging experience.

---

## Features

- **Classic Player Mode**: Take on the role of the codebreaker, guessing the randomly generated secret code.
- **Solver Mode**: Watch as the application, using Knuth's Five-Guess Algorithm, cracks your code with impressive efficiency.
- **Interactive Gameplay**: User-friendly interface with keyboard controls and visual feedback.
- **Customizable Game Rules**:
  - Adjustable code length.
  - Configurable number of colors.
- **Simple and Intuitive Menu**: Navigate between options such as starting a new game, enabling solver mode, or exiting the app.

---

## Installation

### Prerequisites
- A C++ compiler with C++11 or higher support.
- **SFML 2.5** or later installed on your system.
- A terminal/command line environment.

### Steps
1. Clone the repository:
   ```bash
   git clone https://github.com/YourUsername/MasteroftheMind.git
   cd MasteroftheMind
   ```
2. Install **SFML** following the instructions for your system from [SFML's website](https://www.sfml-dev.org/).
3. Build the application:
   ```bash
   g++ -std=c++11 -o Mastermind main.cpp Game.cpp Menu.cpp Solver.cpp -lsfml-graphics -lsfml-window -lsfml-system
   ```
4. Run the application:
   ```bash
   ./Mastermind
   ```

---

## How to Play

1. Launch the application.
2. Choose from the **menu options**:
   - `1. Play Game`: Start a new game where you will act as the codebreaker.
   - `2. Solver Mode`: Set a secret code and let the AI solve it for you.
   - `3. Quit`: Exit the application.
3. **Player Mode**:
   - Use keys (`1-6`) to select colors and press `Enter` to submit your guess.
   - Receive feedback on your guess: the number of correct colors in the right position and correct colors in the wrong position.
   - Crack the secret code to win!
4. **Solver Mode**:
   - Enter your secret code.
   - Watch the solver deduce the correct code step by step with visual feedback.

---

## File Structure

```
|-- Mastermind/
    |-- main.cpp         # Entry point for the application
    |-- Game.h           # Header file for the game logic
    |-- Game.cpp         # Implementation of the game logic
    |-- Menu.h           # Header file for the menu
    |-- Menu.cpp         # Implementation of the menu
    |-- Solver.h         # Header file for Knuth's Five-Guess Algorithm
    |-- Solver.cpp       # Implementation of Knuth's Five-Guess Algorithm
    |-- SFML/            # Dependencies for the SFML library
    |-- arial.ttf        # Font file for the menu text
```

---

## Controls

- **Navigation**: Use keyboard number keys to select menu options.
- **Player Mode**:
  - `1-6`: Select colors for your guess.
  - `Enter`: Submit your guess.

---

## Future Enhancements

- Add a graphical representation for guesses and feedback using SFML.
- Allow users to configure game settings (e.g., code length and number of colors) through the menu.
- Implement a leaderboard for tracking player performance.

---

## License

This project is released under the **MIT License**. Feel free to modify and distribute it.

---

## Credits

- Developed by: Jon-Arve Constantine Grønsberg-Ovesen
- Algorithm: **Donald Knuth's Five-Guess Algorithm**
  

### Layout Design Plan

#### 1. **Main Menu**
- **Header**: Title displayed at the top center (e.g., "MasteroftheMind").
- **Buttons**:
  - **Play Game**: Starts the player mode.
  - **Solver Mode**: Starts the solver mode.
  - **Quit**: Exits the application.
- Use clear fonts (e.g., Arial or similar) with hover effects for active buttons.
- Position the menu items vertically in the center of the window with adequate spacing.

#### 2. **Player Mode Screen**
- **Game Board**:
  - Center area showing empty slots for guesses.
  - Rows display guesses made by the player.
- **Color Selector**:
  - A palette of color options at the bottom, allowing players to click their choices.
- **Feedback Section**:
  - Small pegs to indicate feedback for each guess (correct color/position).
  - Positioned beside each row of guesses.
- **Navigation**:
  - Buttons for actions like “Submit Guess” and “Restart Game.”

#### 3. **Solver Mode Screen**
- **Solver Progress**:
  - Visual display of the solver’s guesses, updated after each step.
- **Input Section**:
  - Allow the player to set the secret code visually.
- **Feedback Display**:
  - Similar to the player mode, showing solver feedback.

#### 4. **General GUI Features**
- **Background**:
  - Use gradients or subtle patterns for a clean look.
- **Animations**:
  - Smooth transitions between screens.
- **Color Scheme**:
  - Utilize contrasting colors for buttons and text to ensure readability.

### Example GUI Layout Mockup
Here’s a conceptual visualization in text format:

```
-------------------------------
|         MasteroftheMind     |
-------------------------------
|        [Play Game]          |
|       [Solver Mode]         |
|         [Quit]              |
-------------------------------
```

When navigating to the player mode:
```
-----------------------------------
|           GAME BOARD            |
|  [Guess 1]   | Feedback |       |
|  [Guess 2]   | Feedback |       |
|       ...                     |
-----------------------------------
|   [Color Options: 1-6]          |
|   [Submit Guess] [Restart]      |
-----------------------------------
```


- Library: **SFML**

---

Of course, Jon! Here are some SFML code snippets for implementing the GUI layout described earlier:

### Main Menu
This snippet creates a basic menu with buttons for "Play Game," "Solver Mode," and "Quit."

```cpp
#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "MasteroftheMind - Main Menu");
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading font\n";
        return -1;
    }

    sf::Text title("MasteroftheMind", font, 50);
    title.setPosition(200, 50);

    sf::Text playButton("Play Game", font, 30);
    playButton.setPosition(300, 150);

    sf::Text solverButton("Solver Mode", font, 30);
    solverButton.setPosition(300, 200);

    sf::Text quitButton("Quit", font, 30);
    quitButton.setPosition(300, 250);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Num1) {
                    std::cout << "Play Game Selected\n";
                } else if (event.key.code == sf::Keyboard::Num2) {
                    std::cout << "Solver Mode Selected\n";
                } else if (event.key.code == sf::Keyboard::Num3) {
                    window.close();
                }
            }
        }

        window.clear();
        window.draw(title);
        window.draw(playButton);
        window.draw(solverButton);
        window.draw(quitButton);
        window.display();
    }

    return 0;
}
```

### Game Board Layout
This snippet creates a basic game board layout with rows for guesses and spaces for feedback.

```cpp
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "MasteroftheMind - Game Board");

    sf::RectangleShape guessSlot(sf::Vector2f(60, 60));
    guessSlot.setFillColor(sf::Color::White);
    guessSlot.setOutlineThickness(2);
    guessSlot.setOutlineColor(sf::Color::Black);

    sf::CircleShape feedbackPeg(10);
    feedbackPeg.setFillColor(sf::Color::Black);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Blue);

        // Draw guess slots
        for (int i = 0; i < 10; ++i) {
            guessSlot.setPosition(100, 50 + (i * 70));
            window.draw(guessSlot);
            // Draw feedback pegs
            feedbackPeg.setPosition(200, 70 + (i * 70));
            window.draw(feedbackPeg);
        }

        window.display();
    }

    return 0;
}
```

### Color Selector
This snippet shows a palette of selectable colors at the bottom of the screen.

```cpp
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "MasteroftheMind - Color Selector");

    sf::CircleShape colorCircle(30);
    sf::Color colors[] = {sf::Color::Red, sf::Color::Green, sf::Color::Blue, sf::Color::Yellow, sf::Color::Cyan, sf::Color::Magenta};

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        // Draw color options
        for (int i = 0; i < 6; ++i) {
            colorCircle.setFillColor(colors[i]);
            colorCircle.setPosition(100 + (i * 100), 500);
            window.draw(colorCircle);
        }

        window.display();
    }

    return 0;
}
```
Thanks for the nudge, Jon! Here’s how you can integrate the GUI layout snippets into your "MasteroftheMind" project effectively:

### Integration Plan
1. **Set Up Your Project**:
   - Ensure all necessary SFML files (`sfml-graphics`, `sfml-window`, `sfml-system`) are included.
   - Place the existing `main.cpp`, `Game.cpp`, `Menu.cpp`, and `Solver.cpp` files into your project folder.

2. **Create GUI Functions**:
   - Break the snippets I provided into separate functions for the main menu, game board, and color selector.
   - Use `Menu.cpp` to handle menu navigation and `Game.cpp` for gameplay logic.

3. **Update the `main.cpp` File**:
   - Integrate the menu function to display the main menu.
   - Use logic to switch between "Player Mode" and "Solver Mode" based on the user’s selection.

### Example Updated Code Structure
Here’s an updated layout for the `main.cpp` file:

```cpp
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu.h"
#include "Game.h"

void showMenu(sf::RenderWindow& window);
void playGame(sf::RenderWindow& window);
void solverMode(sf::RenderWindow& window);

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "MasteroftheMind");
    while (window.isOpen()) {
        showMenu(window);
    }
    return 0;
}

void showMenu(sf::RenderWindow& window) {
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading font\n";
        return;
    }

    sf::Text title("MasteroftheMind", font, 50);
    title.setPosition(200, 50);

    sf::Text playButton("Play Game (1)", font, 30);
    playButton.setPosition(300, 150);

    sf::Text solverButton("Solver Mode (2)", font, 30);
    solverButton.setPosition(300, 200);

    sf::Text quitButton("Quit (3)", font, 30);
    quitButton.setPosition(300, 250);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Num1) {
                    playGame(window);
                } else if (event.key.code == sf::Keyboard::Num2) {
                    solverMode(window);
                } else if (event.key.code == sf::Keyboard::Num3) {
                    window.close();
                }
            }
        }

        window.clear();
        window.draw(title);
        window.draw(playButton);
        window.draw(solverButton);
        window.draw(quitButton);
        window.display();
    }
}

void playGame(sf::RenderWindow& window) {
    // Call game board and gameplay logic functions here
    std::cout << "Launching Player Mode...\n";
}

void solverMode(sf::RenderWindow& window) {
    // Call solver mode GUI functions here
    std::cout << "Launching Solver Mode...\n";
}
```
Here are more SFML-based GUI functions to enrich your "MasteroftheMind" project with additional features and interactivity:

---

### Function: Display Feedback for Guesses
This function visually updates the feedback for each guess (e.g., black pegs for correct position and color, white pegs for correct color but wrong position).

```cpp
void drawFeedback(sf::RenderWindow& window, const std::vector<int>& feedback, int row) {
    sf::CircleShape feedbackPeg(10); // Small pegs for feedback
    feedbackPeg.setOutlineThickness(1);
    feedbackPeg.setOutlineColor(sf::Color::Black);

    for (size_t i = 0; i < feedback.size(); ++i) {
        if (feedback[i] == 1) {
            feedbackPeg.setFillColor(sf::Color::Black); // Correct position and color
        } else if (feedback[i] == 0) {
            feedbackPeg.setFillColor(sf::Color::White); // Correct color but wrong position
        } else {
            feedbackPeg.setFillColor(sf::Color::Transparent); // No feedback
        }
        feedbackPeg.setPosition(400 + (i * 20), 70 + (row * 70));
        window.draw(feedbackPeg);
    }
}
```

---

### Function: Draw Color Palette for Selection
This function renders a row of selectable colors at the bottom of the screen. Players can click a color to choose it for their guess.

```cpp
void drawColorPalette(sf::RenderWindow& window) {
    sf::CircleShape colorCircle(30); // Color options as circles
    sf::Color colors[] = {sf::Color::Red, sf::Color::Green, sf::Color::Blue, sf::Color::Yellow, sf::Color::Cyan, sf::Color::Magenta};

    for (int i = 0; i < 6; ++i) {
        colorCircle.setFillColor(colors[i]);
        colorCircle.setOutlineThickness(2);
        colorCircle.setOutlineColor(sf::Color::Black);
        colorCircle.setPosition(100 + (i * 100), 500); // Positioned horizontally
        window.draw(colorCircle);
    }
}
```

---

### Function: Create Game Board Slots
This function draws rows of empty slots where players input their guesses.

```cpp
void drawGameBoard(sf::RenderWindow& window, int rows) {
    sf::RectangleShape guessSlot(sf::Vector2f(60, 60));
    guessSlot.setFillColor(sf::Color::White);
    guessSlot.setOutlineThickness(2);
    guessSlot.setOutlineColor(sf::Color::Black);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < 4; ++j) { // 4 slots per row
            guessSlot.setPosition(100 + (j * 70), 50 + (i * 70));
            window.draw(guessSlot);
        }
    }
}
```

---

### Function: Display Solver Progress
In Solver Mode, this function updates the GUI dynamically to show the solver’s guesses as it deduces the code.

```cpp
void drawSolverProgress(sf::RenderWindow& window, const std::vector<std::vector<int>>& guesses) {
    sf::RectangleShape slot(sf::Vector2f(60, 60));
    slot.setOutlineThickness(2);
    slot.setOutlineColor(sf::Color::Black);

    for (size_t row = 0; row < guesses.size(); ++row) {
        for (size_t col = 0; col < guesses[row].size(); ++col) {
            slot.setFillColor(sf::Color(guesses[row][col], guesses[row][col], guesses[row]

```
Here’s a complete "How-To Guide" for the "MasteroftheMind" project:

---

## **MasteroftheMind: Complete How-To Guide**

### **Index**
1. **Introduction**
2. **File List and Project Structure**
3. **Setup Instructions**
4. **Gameplay Modes**
5. **All GUI Code Snippets**
6. **Future Enhancements**
7. **Last Words**

---

### **1. Introduction**
MasteroftheMind is a modern implementation of the classic code-breaking game, Mastermind, built with C++ and SFML. It features both a player mode and an automated solver mode powered by Donald Knuth's Five-Guess Algorithm. This guide provides step-by-step instructions on how to set up, play, and expand upon the project.

---

### **2. File List and Project Structure**
The project structure is organized for clarity and scalability. Here’s the file list:

| File Name     | Purpose                                        |
|---------------|------------------------------------------------|
| `main.cpp`    | Entry point for the application.              |
| `Game.h`      | Header file for the game logic.               |
| `Game.cpp`    | Implementation of the game logic.             |
| `Menu.h`      | Header file for the menu.                     |
| `Menu.cpp`    | Implementation of the menu.                   |
| `Solver.h`    | Header file for Knuth's algorithm.            |
| `Solver.cpp`  | Implementation of Knuth's algorithm.          |
| `SFML/`       | Folder containing SFML dependencies.          |
| `arial.ttf`   | Font file for menu text.                      |

---

### **3. Setup Instructions**
#### **Prerequisites**
- C++ compiler (supporting C++11 or higher).
- SFML 2.5 or later installed on your system.
- Terminal or command line environment.

#### **Steps**
1. **Clone the Repository**:
   ```bash
   git clone https://github.com/YourUsername/MasteroftheMind.git
   cd MasteroftheMind
   ```
2. **Install SFML**:
   Follow installation instructions specific to your operating system [here](https://www.sfml-dev.org/).
3. **Build the Application**:
   Compile the files using:
   ```bash
   g++ -std=c++11 -o Mastermind main.cpp Game.cpp Menu.cpp Solver.cpp -lsfml-graphics -lsfml-window -lsfml-system
   ```
4. **Run the Application**:
   ```bash
   ./Mastermind
   ```

---

### **4. Gameplay Modes**
#### **Player Mode**:
1. Select "Play Game" from the menu.
2. Use keys (1-6) to select colors and press Enter to submit your guess.
3. Feedback is provided for each guess:
   - Black peg: Correct color in correct position.
   - White peg: Correct color in wrong position.

#### **Solver Mode**:
1. Choose "Solver Mode" from the menu.
2. Enter the secret code.
3. Watch Knuth’s algorithm deduce the correct code step by step.

---

### **5. All GUI Code Snippets**
#### **Main Menu**
```cpp
void showMenu(sf::RenderWindow& window) {
    // Menu GUI Code (provided in earlier responses)
}
```

#### **Game Board**
```cpp
void drawGameBoard(sf::RenderWindow& window, int rows) {
    // Game Board GUI Code
}
```

#### **Color Palette**
```cpp
void drawColorPalette(sf::RenderWindow& window) {
    // Color Palette GUI Code
}
```

#### **Feedback Pegs**
```cpp
void drawFeedback(sf::RenderWindow& window, const std::vector<int>& feedback, int row) {
    // Feedback Pegs GUI Code
}
```

#### **Solver Progress**
```cpp
void drawSolverProgress(sf::RenderWindow& window, const std::vector<std::vector<int>>& guesses) {
    // Solver Progress GUI Code
}
```

Feel free to customize these snippets for your project!

---

### **6. Future Enhancements**
Suggestions for expanding the project:
1. **Graphical Enhancements**:
   - Add animations for smooth transitions and gameplay.
2. **Settings Configuration**:
   - Allow players to adjust game settings like code length and number of colors.
3. **Leaderboard**:
   - Implement a leaderboard for tracking player performance.

---

### **7. Last Words**
Congratulations on setting up and exploring MasteroftheMind! Whether you’re cracking codes as a player or watching the solver demonstrate the power of algorithms, this project is a fantastic blend of logic, interactivity, and creativity. The implementation of Knuth's algorithm showcases how advanced techniques can enrich classic games.

MasteroftheMind is just getting started! 🚀💻Here’s a complete "How-To Guide" for the "MasteroftheMind" project:

---

## **MasteroftheMind: Complete How-To Guide**
https://github.com/GizzZmo/MasteroftheMind/

