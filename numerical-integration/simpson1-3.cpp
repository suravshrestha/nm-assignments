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
    float s1 = 0, s2 = 0;

    if (n % 2 == 1) ++n;
    for (int i = 1; i < n; ++i)
    {
        float x = x0 + i * h;
        if (i % 2 == 0)
        {
            s1 += f(x);
        }
        else
        {
            s2 += f(x);
        }
    
    }

    float integral = (h / 3) * (f(x0) + f(xn) + 2 * s1 + 4 * s2);

    cout << "The value of the integral is: " << integral << '\n';
    
    return 0;
}
