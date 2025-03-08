#include "Solver.h"
#include <cmath>
#include <cstdlib>
#include <algorithm>

Solver::Solver(int codeLength, int numColors)
    : codeLength(codeLength), numColors(numColors) {
    reset();
}

void Solver::generateAllCodes() {
    possibleCodes.clear();
    std::vector<int> code(codeLength, 0);
    for (int i = 0; i < pow(numColors, codeLength); ++i) {
        for (int j = 0; j < codeLength; ++j) {
            code[j] = (i / (int)pow(numColors, j)) % numColors;
        }
        possibleCodes.push_back(code);
    }
}

void Solver::reset() {
    generateAllCodes();
    currentGuess = {0, 0, 1, 1}; // Knuth suggests starting with this guess
}

std::vector<int> Solver::makeGuess() {
    if (!currentGuess.empty()) {
        return currentGuess;
    }

    // Default to the first possible code as the guess
    currentGuess = possibleCodes[0];
    return currentGuess;
}

void Solver::receiveFeedback(int correctPosition, int correctColor) {
    prunePossibleCodes(correctPosition, correctColor);
    if (!possibleCodes.empty()) {
        currentGuess = possibleCodes[0];
    }
}

int Solver::calculateFeedback(const std::vector<int>& guess, const std::vector<int>& code) {
    int correctPosition = 0, correctColor = 0;
    std::vector<int> codeCount(numColors, 0), guessCount(numColors, 0);

    for (int i = 0; i < codeLength; ++i) {
        if (guess[i] == code[i]) {
            ++correctPosition;
        } else {
            ++codeCount[code[i]];
            ++guessCount[guess[i]];
        }
    }

    for (int i = 0; i < numColors; ++i) {
        correctColor += std::min(codeCount[i], guessCount[i]);
    }

    return (correctPosition << 4) | correctColor; // Encode feedback as a single value
}

void Solver::prunePossibleCodes(int correctPosition, int correctColor) {
    std::vector<std::vector<int>> newPossibleCodes;

    for (const auto& code : possibleCodes) {
        if (calculateFeedback(currentGuess, code) == (correctPosition << 4 | correctColor)) {
            newPossibleCodes.push_back(code);
        }
    }

    possibleCodes = newPossibleCodes;
}
```

---
