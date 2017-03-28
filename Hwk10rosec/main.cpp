#include <iostream>
#include <time.h>
#include <vector>
#include <iomanip>

#define clearScreen cout<<string(25,'\n')

using namespace std;

string descriptions[] = {
  "Aces:",
  "Twos:",
  "Threes:",
  "Fours:",
  "Fives:",
  "Sixes:",
  "3 of a Kind:",
  "4 of a Kind:",
  "Full House:",
  "Sm. Straight:",
  "Lg. Straight:",
  "Yhatzee!:",
  "Chance:"

};

void displayBoard(vector<int> scoreTable)
{
    for (int i = 0; i < 13; i++)
        cout << setw(3) << i << setw(15) << descriptions[i] << " " << setw(3) << scoreTable[i] << endl;
}

string printDieTop(int Value)
{
    switch(Value)
    {
    case 0:
        return "|     |";
    case 1:
        return "|   0 |";
    case 2:
        return "|   0 |";
    case 3:
        return "| 0 0 |";
    case 4:
        return "| 0 0 |";
    case 5:
        return "| 0 0 |";
    }
}

string printDieMiddle(int Value)
{
    switch(Value)
    {
    case 0:
        return "|  0  |";
    case 1:
        return "|     |";
    case 2:
        return "|  0  |";
    case 3:
        return "|     |";
    case 4:
        return "|  0  |";
    case 5:
        return "| 0 0 |";
    }
}

string printDieBottom(int Value)
{
    switch(Value)
    {
    case 0:
        return "|     |";
    case 1:
        return "| 0   |";
    case 2:
        return "| 0   |";
    case 3:
        return "| 0 0 |";
    case 4:
        return "| 0 0 |";
    case 5:
        return "| 0 0 |";
    }
}

void randomizeDie(int numDie, vector<int> &dieList)
{
    dieList.resize(numDie);

    for (int i = 0; i < numDie; i++)
        dieList[i] = rand() % 6;
}

void printDie(int numDie, const vector<int> &dieList)
{
    for (int i = 0; i < numDie; i++)
        cout << "+-----+ ";
    cout << endl;

    for (int i = 0; i < numDie; i++)
        cout << printDieTop(dieList[i]) << " ";
    cout << endl;

    for (int i = 0; i < numDie; i++)
        cout << printDieMiddle(dieList[i]) << " ";
    cout << endl;

    for (int i = 0; i < numDie; i++)
        cout << printDieBottom(dieList[i]) << " ";
    cout << endl;

    for (int i = 0; i < numDie; i++)
        cout << "+-----+ ";
    cout << endl;
}

int scoreThroughSix(const vector<int> &diceRolled, int column)
{
    int score = 0;

    for (int i = 0; i < diceRolled.size(); i ++)
        {
            if (diceRolled[i] == column)
                score += (diceRolled[i] + 1);
        }
    return score;
}

int findPair(const vector<int> &diceRolled, int column, int numPairs)
{
    int kind = 0;
    int score = 0;

    for (int i = 0; i < diceRolled.size(); i++)
        {
            if (diceRolled[i] == diceRolled[i + 2])
            {
               kind = 3;
               score = (diceRolled[i] + 1)*3;
            }
            else if (diceRolled[i] == diceRolled[i + 3])
            {
               kind = 4;
               score = (diceRolled[i] + 1)*4;
            }
            else if (diceRolled[i] == diceRolled[i + 4])
            {
               kind = 5;
            }
        }
        switch (kind)
        {
        case 3:
            if (column == 6)
                return score;
        case 4:
            if (column == 7)
                return score;
        case 5:
            if (column == 11)
                return 50;
        }
        return 0;
}

int fullHouse(const vector<int> &diceRolled)
{
    for (int i = 0; i < diceRolled.size(); i++)
    {
        if (diceRolled[i] == diceRolled[i + 1] && diceRolled[i + 2] == diceRolled[i + 3] == diceRolled[i + 4] ||
            diceRolled[i] == diceRolled[i + 1] == diceRolled[i + 2] && diceRolled[i + 3] == diceRolled[i + 4])
            return 25;
    }
    return 0;
}

int straight(const vector<int> &diceRolled, bool isLgSraight)
{
    int counter = 0;

    for (int i = 0; i < diceRolled.size(); i++)
    {
        if (diceRolled[i] + 1 == diceRolled[i + 1])
            counter++;
    }

    if ((counter == 3 || counter == 4) && !isLgSraight)
        return 30;

    if (counter == 4 && isLgSraight)
        return 40;

    return 0;
}

int scoreDie(vector<int> diceRolled, int column)
{
    sort(diceRolled.begin(), diceRolled.end());

    switch (column)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        return scoreThroughSix(diceRolled, column);
    case 6:
        return findPair(diceRolled, column, 3);
    case 7:
        return findPair(diceRolled, column, 4);
    case 8:
        return fullHouse(diceRolled);
    case 9:
        return straight(diceRolled, false);
    case 10:
        return straight(diceRolled, true);
    case 11:
        return findPair(diceRolled, column, 5);
    }
}

void rollReroll(vector<int> &diceRolled, int &die)
{
    printDie(5, diceRolled);
    cout << "Select die to re-roll (enter zero when done): ";
    cin >> die;

    diceRolled[die - 1] = rand() % 6;

    clearScreen;
}

void doTurn(vector<int> &scoresTable, vector<int> diceRolled)
{
    randomizeDie(5, diceRolled);
    int rowNum;
    int die = 1;

    while (die != 0)
        rollReroll(diceRolled, die);
    printDie(5, diceRolled);
    displayBoard(scoresTable);

    cout << "Select which row: ";
    cin >> rowNum;

    scoresTable[rowNum] = 0 + scoreDie(diceRolled, rowNum);

    clearScreen;
    displayBoard(scoresTable);
}

int main()
{
    srand(time(0));

    vector<int> scoresTableOne(13, -1);
    vector<int> scoresTableTwo(13, -1);
    vector<int> diceRolled(5); //fyi, in the vector int 0 is equivalent to the die 1, int 1 is equivalent to the die 2, etc.

    while (true)
    {
        cout << "Player 1's Turn!" << endl;
        doTurn(scoresTableOne, diceRolled);

        cout << "Player 2's Turn!" << endl;
        doTurn(scoresTableTwo, diceRolled);
    }
}
