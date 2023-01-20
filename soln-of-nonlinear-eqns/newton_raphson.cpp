#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double f(double x)
{
    return x * sin(x) + cos(x);
}

/* f'(x) */
double f_(double x)
{
    return x * cos(x);
}

int main()
{
    double x0; /* Initial guess */
    cout << "Enter initial guess: ";
    cin >> x0;

    double error = 0.0001;

    cout << "\nInitial guess = " << x0 << '\n';
    cout << "Tolerable error = " << error << '\n';

    cout << "\nNewton-Raphson method\n" << left;
    cout << setw(15) << "Step" 
         << setw(15) << "x0" 
         << setw(15) << "f(x0)" 
         << setw(15) << "f'(x0)" 
         << setw(15) << "x1"
         << setw(15) << "f(x1)" << '\n';

    int step = 1;
    double x1;

    do
    {
        double f_x0 = f_(x0); /* f'(x0) */

        if (f_x0 == 0.0f)
        {
            cout << "Newton's method did not converge.\n";
            return -1;
        }

        double fx0 = f(x0);

        x1 = x0 - fx0 / f_x0;

        cout << setw(15) << step
             << setw(15) << x0
             << setw(15) << fx0
             << setw(15) << f_x0
             << setw(15) << x1
             << setw(15) << f(x1) << '\n';

        x0 = x1;

        ++step;
    } while (fabs(f(x1)) > error);

    cout << "\nRoot = " << x1 << '\n';   

    return 0;
}
