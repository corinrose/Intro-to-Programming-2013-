#include <iostream>
#include <iomanip>

using namespace std;

double pow(double x, double y)
{
    double result = x;
    for (int i = 0; i < y - 1; i++)
    {
        result = result*x;
    }
    return result;
}

int main()
{
    double pi = 3.0;
    for (int i = 2; i < 1000000; i += 2)
    {
        pi += pow(-1,i/2+1)*4/(i*(i+1)*(i+2));
        if (i % 1000 == 0)
            cout << setprecision(50) << pi << endl;
    }
}
