/* Linear curve fitting for the curve y=a+bx */

#include <iostream>

using namespace std;

int main()
{
    double sum_x = 0, sum_xx = 0, sum_y = 0, sum_xy = 0;

    int n;
    cout << "Enter the number of data: ";
    cin >> n;

    double x, y;
    cout << "\nEnter the data for (x, y):\n";
    for (int i = 0; i < n; ++i)
    {
        cout << "(x" << i << ", y" << i << "): ";
        cin >> x >> y;

        sum_x += x;
        sum_xx += x * x;
        sum_y += y;
        sum_xy += x * y;
    }

    double d = n * sum_xx - sum_x * sum_x;
    double d1 = sum_y * sum_xx - sum_x * sum_xy;
    double d2 = n * sum_xy - sum_y * sum_x;

    double a = d1 / d;
    double b = d2 / d;

    cout << "\nFor linear best fit curve y=a+bx,";
    cout << "\na = " << a;
    cout << "\nb = " << b << '\n';

    return 0;
}
