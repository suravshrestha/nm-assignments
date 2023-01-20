/* Linear curve fitting for the curve y=a+bx+cx^2+...+kx^n */

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, d;
    cout << "Enter the number of data: ";
    cin >> n;

    cout << "Enter the degree of the polynomial: ";
    cin >> d;

    float x[n], y[n];
    float a[d + 1][d + 2] = {}; /* Normal equations' matrix */

    cout << "\nEnter the data points (x, y):\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i <= d; i++)
    {
        for (int j = 0; j <= d; j++)
        {
            for (int k = 0; k < n; k++)
            {
                a[i][j] += pow(x[k], i + j);
            }
        }

        for (int j = 0; j < n; j++)
        {
            a[i][d + 1] += pow(x[j], i) * y[j];
        }
    }


    /* Convert the augmented matrix to diagonal matrix */
    for (int j = 0; j <= d; ++j)
    {
        if (fabs(a[j][j]) <= 0.0005)
        {
            cout << "Mathematical Error: Pivot element is zero\n";
            return -1;
        }

        for (int i = 0; i <= d; ++i)
        {
            if (i != j)
            {
                float ratio = a[i][j] / a[j][j];

                for (int k = 0; k <= d + 1; ++k)
                {
                    a[i][k] -= ratio * a[j][k];
                }
            }
        }
    }

    cout << "\nFor polynomial best fit curve\ny = a0 + a1x + a2x^2 + ... + anx^n,";
    for (int i = 0; i <= d; ++i)
    {
        cout.precision(5);
        cout << "\na" << i << " = " << a[i][d + 1] / a[i][i];
    }

    return 0;
}
