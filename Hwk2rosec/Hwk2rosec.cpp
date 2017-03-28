//DrH  Score 100%
#include <iostream>

int main()
{
    int x;
    int y;
    int i = 1;

    std::cout << "Enter x: ";
    std::cin >> x;
    std::cout << "Enter y: ";
    std::cin >> y;

    for (int i = 1; i <= x; i++)
    {
        std::cout << i << " " << i*y << "\n";
    }
}

