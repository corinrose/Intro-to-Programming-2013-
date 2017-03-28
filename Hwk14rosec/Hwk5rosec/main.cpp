// DrH:  95%

#include <iostream>
#include <string>

using namespace std;

string mc(char x)   // DrH: mc is a big obscure for a function name
{
    switch (x)
    {

    case 'a':
        return "._   ";
        break; // DrH: no need for break if you return (it never gets here)
    case 'b':
        return "_...   ";
        break;
    case 'c':
        return "_._.   ";
        break;
    case 'd':
        return "_..   ";
        break;
    case 'e':
        return ".   ";
        break;
    case 'f':
        return ".._.   ";
        break;
    case 'g':
        return "__.   ";
        break;
    case 'h':
        return "....   ";
        break;
    case 'i':
        return "..   ";
        break;
    case 'j':
        return ".___   ";
        break;
    case 'k':
        return "_._   ";
        break;
    case 'l':
        return "._..   ";
        break;
    case 'm':
        return "__";
        break;
    case 'n':
        return "_.";
        break;
    case 'o':
        return "___   ";
        break;
    case 'p':
        return ".__.   ";
        break;
    case 'q':
        return "__._   ";
        break;
    case 'r':
        return "._.   ";
        break;
    case 's':
        return "...   ";
        break;
    case 't':
        return "_   ";
        break;
    case 'u':
        return ".._   ";
        break;
    case 'v':
        return "..._   ";
        break;
    case 'w':
        return ".__   ";
        break;
    case 'x':
        return "_.._   ";
        break;
    case 'y':
        return "_.__   ";
        break;
    case 'z':
        return "__..   ";
        break;
    case ' ':
        return "       ";
        break;
    }

    // DrH: return here to handle unrecognized character
}

int main()
{
    string str;

    while (true)
    {
        cout << "Enter Text: ";
        getline(cin,str);

        int x = str.length();  // DrH: no need for this variable, just put str.length() into the for loop

        for (int i = 0; i < x; i++)
        {
            char c = str[i];
            cout << mc(c);
        }

        cout << endl;
    }
}
