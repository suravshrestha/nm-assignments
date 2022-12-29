#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double f(double x)
{
    return x * sin(x) + cos(x);
}

int main()
{
    double a = 0, b = 0;

    /* Find the interval */
    while (f(a) * f(b) > 0)
    {
        ++b;
        if (f(a) * f(b) < 0)
        {
            break;
        }

        --a;
    }

    double error = 0.0001;

    cout << "Initial guess: a = " << a << ", b = " << b << '\n';
    cout << "Tolerable error = " << error << '\n';

    cout << "\nBisection method\n" << left;
    cout << setw(15) << "Step" 
         << setw(15) << "a" 
         << setw(15) << "b" 
         << setw(15) << "c" 
         << setw(15) << "f(c)" << '\n';

    int step = 1;
    double c;

    do
    {
        c = a + (b - a) / 2.0f;

        cout << setw(15) << step
             << setw(15) << a 
             << setw(15) << b 
             << setw(15) << c 
             << setw(15) << f(c) << '\n';

        if (f(a) * f(c) < 0)
        {
            b = c;
        } else
        {
            a = c;
        }

        ++step;
    } while (fabs(f(c)) > error);

    cout << "\nRoot = " << c << '\n';   

    return 0;
}
