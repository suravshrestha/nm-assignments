/* Solution of ordinary differential equation using RK2 method */

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
        double k2 = h * f(x + h, y + k1);
        double k = k2 - (k2 - k1) / 2.0f;

        y += k;
        x += h;

        cout << x << '\t' << y << '\n';
    }

    return 0;
}
