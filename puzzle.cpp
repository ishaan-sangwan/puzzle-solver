#include <iostream>
#include "puzzle.h"
using namespace std;


//constructor that does not take anything as argument
//inputs a file into the variable puzzleStraem that has the puzzle in it
//readPuzzle put the puzzle into the board
//inputs a file into the variable wordStream that has searchable word in it
//readWords puts the words into theWords variable

Puzzle::Puzzle() : theBoard(0,0)
{
    openFile("enter the puzzle file", puzzleStream);
    readPuzzle();
    openFile("enter the file for the words to be searched", wordStream);
    readWords();
}


//this function is going to open a file
void Puzzle:: openFile(const string & message, ifstream & infile)
{
    string name;
    do
    {
        infile.clear();
        cout<<message<<':'<<endl;
        cin>>name;
        infile.open(name.c_str());
    } while (!infile);
}


//puts the puzzle in board
void Puzzle::readWords(){
    string thisWord;
    int numEntries = 0;

    for (; wordStream >> thisWord; numEntries++)
    {   theWords.push_back(thisWord);
        if ( numEntries != 0 && theWords[numEntries]<theWords[numEntries -1])
        {
            cerr<<"dictionary is not sorted ... skipping"<<endl;
            continue;
        }
    }
}

vector<char> toVec( const string & str )
{
    vector<char> v (str.length());
    for ( int i =0; i<str.length(); i++)
    {
    
        v[i]  = str[i];

    }
    return v;
}

void Puzzle::readPuzzle()
{

    string oneline;

    if ( getline(puzzleStream, oneLine).eof() )
    {
        return;
    }

    int columns  = oneLine.length();

    theBoard.push_back(toVec(oneLine));

    while(!(getline(puzzleStream, oneline)).eof())
    {
        if(oneline.length() != columns)
        {
            cerr<<"puzzle is not rectangular"
        }
        else
        {
            theBoard.push_back(toVec(oneline));
        }
    }
}

int Puzzle::solvePuzzle() const
{
    int matches = 0;
    for(int r= 0;   r< theBoard.numrows(); r++)
    {
        for(int c=0 ; c<theBoard.numcols(); c++)
        {
            for(int rd = -1 ; rd <=1; rd++)
            {
                for(cd =-1 ; cd <=1; cd ++)
                {
                    if ( rd != 0 || cd != 0 )
                    {
                        matches += solveDirection(r,c,rd,cd);
                    }
                }
            }
        }
    }
    return matches;
}


bool isPrefix(const string & prefix, const string & word)
{
    if ( word.length() < prefix.length() )
    {
        return false;
    }

    for ( int i =0 ; i<prefix.length(); i++ )
    {
        if ( prefix[i] != word[i] )
        {
            return false;
        }
        return true;
    }
}

int Puzzle::solveDirection(int baseRow, int baseCol, int rowDelta, int colDeta) const
{

    string word;
    int numMatches = 0;

    word = theBoard[baseRow][baseCol];

    for (int i = baseRow + rowDelta, j = baseCol+colDeta; j = baseCol+colDeta; i>=0 && j >=0 && i< theBoard.numrows() && j< theBoard.numcols; i+= rowDelta, j+=colDeta)
    {
        word += theBoard[i][j];

        vector<string>::const_iterator itr;

        if(itr = lower_bound(theWords.begin(), theWords.end(), word))
            break;
        
        if ( *itr == word)
        {
            numMatches++;
            cout<<"found"<<word<<"at"<<baseRow<<" "<<baseCol<<"to"<<i<<" "<<j<<endl;
        }

    }
    
    return numMatches;

}