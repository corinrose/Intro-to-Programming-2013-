//DrH  Score 100%
#include <cmath>   // I changed this
#include <iostream>

int main()
{
	double x;
	double y;
	std::cout << "Please Enter Side One: ";
	std::cin >> x;
	std::cout << "Please Enter Side Two: ";
	std::cin >> y;
	while (x < 0)
	{
		std::cout << "Your first side is negative!!!\n\a";
		std::cout << "Please Reenter Side One: ";
		std::cin >> x;
	}
	while (y < 0)
	{
		std::cout << "Your second side is negative!!!\n\a";
		std::cout << "Please Reenter Side Two: ";
		std::cin >> y;

	}
		double z = (x*x) + (y*y);
		std::cout << "The Hypotenuse is " << sqrt(z) << "\n";
}
