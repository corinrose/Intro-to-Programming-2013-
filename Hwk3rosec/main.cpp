//DrH  Score 100%

#include <iostream>

using namespace std;

int main()
{
    string str;
    cout << "Enter your name: ";
    cin >> str;

    int x = str.length();
    str = "|  " + str + "  |\n";

    string lines(x+4,'-');
    lines = "+" + lines + "+\n";

    string spacer(x+4, ' ');
    spacer = "|" + spacer + "|\n";

    cout << lines << spacer << str << spacer << lines;
}
