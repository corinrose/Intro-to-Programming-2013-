#include <iostream>
#include <vector>
#include <time.h>
#include <cmath>


using namespace std;

struct Card
{
    int  _rank;
    char _suit;
};


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

vector<Card> buildDeck()
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
    return deck;

}

void showDeck(const vector<Card> &deck)
{
    for (int i = 0; i <= deck.size(); i ++)
    {
        cout << nameCard(deck[i]) << "\n";
    }
}

vector<Card> shuffle(vector<Card> &deck)
{
    for (int i = 0; i < deck.size()*100; i++)
    {
        int r1 = rand() % deck.size();
        int r2 = rand() % deck.size();

        Card tmp = deck[r1];
        deck[r1] = deck[r2];
        deck[r2] = tmp;
    }
    return deck;
}

vector<Card> buildShuffledDeck()
{
    vector<Card> deck = buildDeck();
    return shuffle(deck);
}

void cutDeck(vector<Card> deck, vector<Card> &deck1, vector<Card> &deck2)
{
    int cutSize = deck.size()/2 + 1;

    for (int i = 0; i < cutSize; i++)
    {
        deck1[i] = deck.back();
        deck.pop_back();
    }
    for (int i = 0; i < cutSize; i ++)
    {
        deck2[i] = deck[i];
    }

}

bool checkTopCard(vector<Card> &deck1, vector<Card> &deck2)
{
    Card disp1;
    Card disp2;

    deck1[deck1.size() - 1] = disp1;
    deck2[deck2.size() - 1] = disp2;

    if (disp1._rank < disp2._rank)
    {
        return 0;
    }
}

int main()
{

    srand(time(0));

    vector<Card> deck = buildDeck();

    deck = shuffle(deck);

    vector<Card> deck1((deck.size()-1)/2);
    vector<Card> deck2((deck.size()-1)/2);

    cutDeck(deck, deck1, deck2);

    showDeck(deck1);
    cout << "---------\n";
    showDeck(deck2);


    checkTopCard(deck1, deck2);

    return 0;

}
