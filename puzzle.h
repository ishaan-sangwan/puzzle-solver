#ifndef PUZZLE_CPP
#define PUZZLE_CPP

#include<string>
#include<vector>
#include<algorithm>
#include "matrix.h"

class Puzzle
{
    public:
        Puzzle();
        int solvePuzzle() const;
    private:
//variables that are used in the class
        matrix<int> theBoard;
        vector<string> theWords;
        ifstream puzzleStream;
        ifstream wordStream;

//functions used in the constructor
        void openFile(const string & message, ifstream & inFile);
        void readPuzzle();
        void readWords();

//functon that solves the puzzle
        int solveDirection(int baseRow, int baseCol, int rowDelta, int colDelta) const;

};

#endif


