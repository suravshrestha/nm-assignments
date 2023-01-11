/* Solution of system of linear equations using Gauss Elimination method */

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cout << "Enter the number of variables: ";
    cin >> n;

    float a[n][n + 1];

    cout << "Enter the elements of augmented matrix row-wise:\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n + 1; ++j)
        {
            cin >> a[i][j];     
        }
    }

    /* Convert the augmented matrix to upper triangular matrix */
    for (int j = 0; j < n - 1; ++j)
    {
        if (fabs(a[j][j]) <= 0.0005)
        {
            cout << "Mathematical Error: Pivot element is zero\n";
            return -1;
        }

        for (int i = j + 1; i < n; ++i)
        {
            float ratio = a[i][j] / a[j][j];

            for (int k = 0; k < n + 1; ++k)
            {
                a[i][k] -= ratio * a[j][k];
            }
        }
    }
    
    float x[n] = {0};
    for (int i = n - 1; i >= 0; --i)
    {
        float s = 0;
        for (int j = i + 1; j < n; ++j)
        {
            s += a[i][j] * x[j];
        }

        if (fabs(a[i][i]) <= 0.0005)
        {
            cout << "Mathematical Error: Pivot element is zero\n";
            return -1;
        }

        x[i] = (a[i][n] - s) / a[i][i];
    }

    cout << "The solution is: ";
    for (int i = 0; i < n; ++i)
    {
        cout << x[i] << ' ';
    }

    cout << '\n';

    return 0;
}
