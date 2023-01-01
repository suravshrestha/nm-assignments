/* Solution of ordinary differential equation using Euler's method */

#include <iostream>

using namespace std;

/* dy/dx = f(x, y) */
double f(double x, double y)
{
    return x * x + 2 * x - y;
}

int main()
{
    double x, y, h;
    int n;

    cout << "Enter the values of x0, y0, h, n: ";
    cin >> x >> y >> h >> n;

    cout << x << '\t' << y << '\n';

    for (int i = 0; i < n; ++i)
    {
        y += h * f(x, y);
        x += h;

        cout << x << '\t' << y << '\n';
    }

    return 0;
}
