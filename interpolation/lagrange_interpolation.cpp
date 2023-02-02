#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter the number of data: ";
    cin >> n;

    float x[n], y[n];

    cout << "\nEnter the data points (x, y):\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> x[i] >> y[i];
    }

    float xp;
    cout << "\nEnter the value of x for interpolation: ";
    cin >> xp;

    float s = 0;
    for (int i = 0; i < n; ++i)
    {
        float p = y[i];
        for (int j = 0; j < n; ++j)
        {
            if (i != j)
            {
                if (x[i] == x[j])
                {
                    cout << "Error: Division by zero.\n";
                    return -1;
                }

                p *= (xp - x[j]) / (x[i] - x[j]);
            }
        }
        s += p;
    }

    cout << "Interpolated value at x = " << xp << " is " << s << '\n';

    return 0;
}
