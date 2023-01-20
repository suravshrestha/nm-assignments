/* Solution of system of linear equations using Gauss-Jordan method */

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

    /* Convert the augmented matrix to diagonal matrix */
    for (int j = 0; j < n; ++j)
    {
        if (fabs(a[j][j]) <= 0.0005)
        {
            cout << "Mathematical Error: Pivot element is zero\n";
            return -1;
        }

        for (int i = 0; i < n; ++i)
        {
            if (i != j)
            {
                float ratio = a[i][j] / a[j][j];

                for (int k = 0; k < n + 1; ++k)
                {
                    a[i][k] -= ratio * a[j][k];
                }
            }
        }
    }

    cout << "The solution is: ";
    for (int i = 0; i < n; ++i)
    {
        cout << a[i][n] / a[i][i] << ' ';
    }

    cout << '\n';

    return 0;
}
