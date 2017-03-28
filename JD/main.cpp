#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

int main()
{
    time_t t;
    double days;

    while (true)
    {
        t = time(0);
        days = t/86400.0 + 40587.5;
        cout << setprecision(10) << 24 << days << endl;
        sleep(1);
    }
}
