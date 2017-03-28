// DrH: 90%   Code could be simplified using a vector for your data model.  See other comments

#include <iostream>

using namespace std;

// DrH: avoid use of global variables when possible (pass data around through arguments as necessary)

    char sqr1 = ' ';
    char sqr2 = ' ';
    char sqr3 = ' ';
    char sqr4 = ' ';
    char sqr5 = ' ';
    char sqr6 = ' ';
    char sqr7 = ' ';
    char sqr8 = ' ';
    char sqr9 = ' ';

    int turn = 0;  // DrH: prefer bool variable here

    int rounds = 0;

bool checkUsed(char x)
{
    if (x == 'X' || x == 'O')
    {
            return 0;
    }

    turn = turn xor 1;

    return 1;

}

char input(char c, int p)  // DrH: what are c and p?   add comment or better names
{

    char draw = 'X';

    if (p == 2)
    {
        draw = 'O';
    }

    switch(c)
    {
    case '1':
        if (checkUsed(sqr1))
        {
            sqr1 = draw;
        }
        break;
    case '2':
        if (checkUsed(sqr2))
        {
            sqr2 = draw;
        }
        break;
    case '3':
        if (checkUsed(sqr3))
        {
            sqr3 = draw;
        }
        break;
    case 'q':
        if (checkUsed(sqr4))
        {
            sqr4 = draw;
        }
        break;
    case 'w':
        if (checkUsed(sqr5))
        {
            sqr5 = draw;
        }
        break;
    case 'e':
        if (checkUsed(sqr6))
        {
            sqr6 = draw;
        }
        break;
    case 'a':
        if (checkUsed(sqr7))
        {
            sqr7 = draw;
        }
        break;
    case 's':
        if (checkUsed(sqr8))
        {
            sqr8 = draw;
        }
        break;
    case 'd':
        if (checkUsed(sqr9))
        {
            sqr9 = draw;
        }
        break;
    default:
        cout << "Please only enter 1-9.\n";
        break;
    }
}

void drawBoard()
{
    cout << "+---+---+---+" << endl;
    cout << "| " << sqr1 << " | "  << sqr2 << " | "  << sqr3 <<" |" << endl;
    cout << "+---+---+---+" << endl;
    cout << "| " << sqr4 << " | " << sqr5 << " | " << sqr6 << " |" << endl;
    cout << "+---+---+---+" << endl;
    cout << "| " << sqr7 << " | " << sqr8 << " | " << sqr9 << " |" << endl;
    cout << "+---+---+---+" << endl;
}

void drawKey()
{
    int bloop;// DrH: ??

    cout << string(25,'\n');

    cout << "Boxes correspond to keys as follows: \n";
    cout << "+---+---+---+" << endl;
    cout << "| 1 | 2 | 3 |" << endl;
    cout << "+---+---+---+" << endl;
    cout << "| q | w | e |" << endl;
    cout << "+---+---+---+" << endl;
    cout << "| a | s | d |" << endl;
    cout << "+---+---+---+" << endl << endl;
    cout << "Hit enter when ready.\n";
    cin.ignore();
}

bool checkWin()
{
    // DrH: this conditional is pretty hard to read/understand
    if (((sqr1 == sqr2) && (sqr1 == sqr3) && (sqr1 != ' ') && (sqr2 != ' ') && (sqr3 != ' ')) ||
        ((sqr4 == sqr5) && (sqr4 == sqr6) && (sqr4 != ' ') && (sqr5 != ' ') && (sqr6 != ' ')) ||
        ((sqr7 == sqr8) && (sqr7 == sqr9) && (sqr7 != ' ') && (sqr8 != ' ') && (sqr9 != ' ')) ||
        ((sqr1 == sqr4) && (sqr1 == sqr7) && (sqr1 != ' ') && (sqr4 != ' ') && (sqr7 != ' ')) ||
        ((sqr2 == sqr5) && (sqr2 == sqr8) && (sqr2 != ' ') && (sqr5 != ' ') && (sqr8 != ' ')) ||
        ((sqr3 == sqr6) && (sqr3 == sqr9) && (sqr3 != ' ') && (sqr6 != ' ') && (sqr9 != ' ')) ||
        ((sqr1 == sqr5) && (sqr1 == sqr9) && (sqr1 != ' ') && (sqr5 != ' ') && (sqr9 != ' ')) ||
        ((sqr7 == sqr5) && (sqr7 == sqr3) && (sqr7 != ' ') && (sqr5 != ' ') && (sqr3 != ' ')))
    {
        if (turn == 1)
        {
            cout << string(25,'\n');
            drawBoard();
            cout << "The winner is player 1, congratulations!" << endl;
        }
        else if (turn == 0)
        {
            cout << string(25,'\n');
            drawBoard();
            cout << "The winner is player 2, congratulatons!" << endl;
        }
        return true;
    }
    else if (rounds == 9)
    {
        cout << string(25,'\n');
        drawBoard();
        cout << "It's a tie!!" << endl;
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    drawKey();


    while (true)
    {
        // DrH: declare these variables closer to first use
        char player1;
        char player2;

        cout << string(25,'\n');

        drawBoard();

        do
        {
            cout << "Player One Enter Value: ";
            cin >> player1;

            input(player1, 1);

        } while (turn == 0);

        cout << string(25,'\n');

        if (checkWin())
        {
            break;
        }

        drawBoard();

        rounds += 1;

        do
        {
            cout << "Player Two Enter Value: ";
            cin >> player2;

            input(player2, 2);

        } while (turn == 1);

        rounds += 1;

        if (checkWin())
        {
            break;
        }
    }
}
