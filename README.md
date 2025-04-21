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

https://github.com/GizzZmo/MasteroftheMind/

