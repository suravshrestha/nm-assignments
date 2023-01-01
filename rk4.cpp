/* Solution of ordinary differential equation using RK4 method */

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
        double k1 = h * f(x, y);
        double k2 = h * f(x + h / 2, y + k1 / 2);
        double k3 = h * f(x + h / 2, y + k2 / 2);
        double k4 = h * f(x + h, y + k3);
        double k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;

        y += k;
        x += h;

        cout << x << '\t' << y << '\n';
    }

    return 0;
}
