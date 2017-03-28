//Score 100%

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout << "Enter a number: ";
    int x;
    cin >> x;
    for (int i = 1; i <= x; i ++)
    {
            for (int n = 1; n <= x; n ++)
            {
                cout << setw(3);
                cout << i*n << " ";
            }
        cout << setw(3);
        cout << "\n";
    }
}

