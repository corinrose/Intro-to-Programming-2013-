#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

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


void printDie(int numDie, vector<int> &dieList)
{
    int start = dieList.size();

    dieList.resize(numDie + dieList.size());

    numDie += start;

    for (int i = start; i < numDie; i++)
    {
        dieList[i] = rand() % 6;
    }

    for (int i = start; i < numDie; i++)
    {
        cout << printDieTop(dieList[i]) << " ";
    }

    cout << endl;

    for (int i = start; i < numDie; i++)
    {
        cout << printDieMiddle(dieList[i]) << " ";
    }

    cout << endl;

    for (int i = start; i < numDie; i++)
    {
        cout << printDieBottom(dieList[i]) << " ";
    }

    cout << endl;
}


int main()
{
    srand(time(0));

    vector<int> diceRolled;

    printDie(5, diceRolled);

    //fyi, in the vector int 0 is equivalent to the die 1, int 1 is equivalent to the die 2, etc.

}
