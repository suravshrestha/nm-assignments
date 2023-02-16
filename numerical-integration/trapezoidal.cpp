#include <iostream>

using namespace std;

float f(float x)
{
    return 1 / (1 + x * x);
}

int main()
{
    double x0, xn;
    int n;

    cout << "Enter the lower limit: ";
    cin >> x0;

    cout << "Enter the upper limit: ";
    cin >> xn;

    cout << "Enter the number of sub-intervals: ";
    cin >> n;

    float h = (xn - x0) / n;
    float sum = 0;

    if (n % 2 == 1) ++n;
    for (int i = 1; i < n; ++i)
    {
        float x = x0 + i * h;
        sum = sum + f(x);
    }

    float integral = (h / 2) * (f(x0) + 2 * sum + f(xn));

    cout << "The value of the integral is: " << integral << '\n';

    return 0;
}
