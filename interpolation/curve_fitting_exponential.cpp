/* Linear curve fitting for the curve y=ae^(bx) */

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double sum_x = 0, sum_xx = 0, sum_Y = 0, sum_xY = 0;

    int n;
    cout << "Enter the number of data: ";
    cin >> n;

    double x, y;
    cout << "\nEnter the data points (x, y):\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> x >> y;

        sum_x += x;
        sum_xx += x * x;

        sum_xY += x * log(y);
        sum_Y += log(y);
    }

    double d = n * sum_xx - sum_x * sum_x;
    double d1 = sum_Y * sum_xx - sum_x * sum_xY;
    double d2 = n * sum_xY - sum_Y * sum_x;

    double A = d1 / d;
    double b = d2 / d;

    cout << "\nFor non-linear best fit curve y=ae^(bx),";
    cout << "\na = " << exp(A);
    cout << "\nb = " << b << '\n';

    return 0;
}
