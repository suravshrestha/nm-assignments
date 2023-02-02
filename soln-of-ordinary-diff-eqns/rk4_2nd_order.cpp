/* Solution of 2nd order differential equation using RK4 method */

#include <iostream>

using namespace std;

/* y' = f(x, y, z) = z */
float f(float x, float y, float z)
{
    return z;
}

/* z' = y" = g(x, y, z) */
float g(float x, float y, float z)
{
    return x * z * z - y * y;
}

int main()
{
    float x, y, z, h, xn;

    cout << "Enter the initial values of x0, y0, y'(0): ";
    cin >> x >> y >> z;

    cout << "Enter the step size h: ";
    cin >> h;

    cout << "Enter the value of x at which y is required: ";
    cin >> xn;

    while (x < xn)
    {
        float k1 = h * f(x, y, z);
        float l1 = h * g(x, y, z);

        float k2 = h * f(x + h / 2, y + k1 / 2, z + l1 / 2);
        float l2 = h * g(x + h / 2, y + k1 / 2, z + l1 / 2);

        float k3 = h * f(x + h / 2, y + k2 / 2, z + l2 / 2);
        float l3 = h * g(x + h / 2, y + k2 / 2, z + l2 / 2);

        float k4 = h * f(x + h, y + k3, z + l3);
        float l4 = h * g(x + h, y + k3, z + l3);

        float k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        float l = (l1 + 2 * l2 + 2 * l3 + l4) / 6;

        x += h;
        y += k;
        z += l;
    }

    cout << "\ny(" << xn << ") = " << y << '\n';
    cout << "y'(" << xn << ") = " << z << '\n';

    return 0;
}
