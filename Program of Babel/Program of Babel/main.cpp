//
//  main.cpp
//  Program of Babel
//
//  Created by Corin Rose on 2/10/14.
//  Copyright (c) 2014 R3 Enterprises. All rights reserved.
//

#include <fstream>
#include <time.h>

using namespace std;

char randChar(bool upperCase = false)
{
    int num = 97;
    
    if (upperCase)
        num = 65;
        
    char c = rand() % 29 + 97;
    
    if (c == 26 + num)
        return '.';
    
    if (c == 27 + num)
        return ',';
    
    if (c == 28 + num)
        return ' ';
    
    return c;
}

int main()
{
    time_t timer;
    srand(time(&timer));
    
    string title = "Book of Babel.txt";
    ofstream book = ofstream(title);
    
    for (int page = 0; page < 1; page++)
    {
        for (int line = 0; line < 40; line++)
        {
            for (int character = 0; character < 80; character++)
            {
                char c = randChar();
                switch(c)
                {
                    case '.':
                    {
                        book << ". ";
                        character++;
                        break;
                    }
                    case ',':
                    {
                        book << ", ";
                        character++;
                        break;
                    }
                    default:
                    {
                        book << c;
                        break;
                    }
                        
                }

            }
            book << endl;
        }
        book << endl;
    }

    book.close();
}

