#include <iostream>
#include <vector>

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
    string text = "this is a secret";

    vector<string> words = stringToVect(text);

    for (int i = 0; i < words.size(); i++)
        cout << words[i] << endl;
}
