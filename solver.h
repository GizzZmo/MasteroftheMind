#ifndef SOLVER_H
#define SOLVER_H

#include <vector>
#include <utility>

class Solver {
public:
    Solver(int codeLength, int numColors);
    std::vector<int> makeGuess();
    void receiveFeedback(int correctPosition, int correctColor);
    void reset();

private:
    int codeLength;
    int numColors;
    std::vector<std::vector<int>> possibleCodes;
    std::vector<int> currentGuess;

    void generateAllCodes();
    int calculateFeedback(const std::vector<int>& guess, const std::vector<int>& code);
    void prunePossibleCodes(int correctPosition, int correctColor);
};

#endif // SOLVER_H
