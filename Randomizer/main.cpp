#include <iostream>
#include <time.h>
#include <cmath>
#include <vector>
#include <fstream>

using namespace std;

vector<string> stringToVect(string text)
{
    int numSpaces = 0;
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] == ' ')
            numSpaces++;
    }

    vector<string> words(numSpaces + 1, "");

    int n = 0;

    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] == ' ')
         {
            n++;
            i++;
         }
        words[n] += text[i];
    }

    return words;
}

int main()
{
    srand(time(0));

    string finalText;

    cout << "Enter text to be generated: ";
    getline(cin, finalText);

    vector<string> words = stringToVect(finalText);

    string genWord;
    string genText;

    int counter;
    int startTime = time(0);

    for (int i = 0; i < words.size(); i++)
    {
        genWord = words[i];

        do
        {
            for (int n = 0; n < words[i].length(); n++)
                genWord[n] = char(rand() % 26 + 97);

            cout << genWord << endl;

        } while(genWord != words[i]);

        genText += genWord + ' ';
        cout << genWord << endl;
    }
}
