// DrH: 98%  Build deck in a separate function

#include <iostream>
#include <vector>

using namespace std;

struct Card
{
    int  _rank;   // 2-14
    char _suit;   // one of 'S' 'D' 'H' 'C'
};

// function that returns a description of the card
// "Jack of Spades"  if suit is 'S'  and the rank is 11
string nameCard(Card c)
{
    string cardRank = "InvalidRank";
    string suit = "InvalidSuit";

    switch (c._rank)
    {
        case 2:
           cardRank = "Two";
           break;
        case 3:
           cardRank = "Three";
           break;
        case 4:
           cardRank = "Four";
           break;
        case 5:
           cardRank = "Five";
           break;
        case 6:
           cardRank = "Six";
           break;
        case 7:
           cardRank = "Seven";
           break;
        case 8:
           cardRank = "Eight";
           break;
        case 9:
           cardRank = "Nine";
           break;
        case 10:
           cardRank = "Ten";
           break;
        case 11:
           cardRank = "Jack";
           break;
        case 12:
           cardRank = "Queen";
           break;
        case 13:
           cardRank = "King";
           break;
        case 14:
           cardRank = "Ace";
           break;
    }

    switch (c._suit)
    {
    case 'H':
        suit = " of Hearts";
        break;
    case 'S':
        suit = " of Spades";
        break;
    case 'D':
        suit = " of Diamonds";
        break;
    case 'C':
        suit = " of Clubs";
        break;
    }

    return cardRank + suit;
}

char incrementSuit(char currentSuit)
{
    switch (currentSuit)
    {

    case 'S':
        return 'H';
        break;
    case 'H':
        return 'D';
        break;
    case 'D':
        return 'C';
        break;
    case 'C':
        return 'S';
        break;
    }
}

int main()
{


    vector<Card> deck(51);

    int setRank = 2;
    char setSuit = 'S';

    for (int i = 0; i < 52; i++)
    {
        if (i % 13 == 0)
        {
            setSuit = incrementSuit(setSuit);
            setRank = 2;
        }

        deck[i]._rank = setRank;
        deck[i]._suit = setSuit;

        setRank++;
    }


    for (int i = 0; i < 51; i ++)
    {
        cout << nameCard(deck[i]) << "\n";
    }

    return 0;
}
