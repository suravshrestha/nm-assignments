/* Inverse of a matrix using Gauss-Jordan method */

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cout << "Enter the number of variables: ";
    cin >> n;

    float a[n][2 * n];

    cout << "Enter the elements of the matrix row-wise:\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> a[i][j];     
        }
    }

    /* Create the augmented matrix */
    for (int i = 0; i < n; ++i)
    {
        for (int j = n; j < 2 * n; ++j)
        {
            a[i][j] = (i == j - n) ? 1 : 0;
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

                for (int k = 0; k < 2 * n; ++k)
                {
                    a[i][k] -= ratio * a[j][k];
                }
            }
        }
    }

    /* Divide each row by its diagonal element */
    for (int i = 0; i < n; ++i)
    {
        double temp = a[i][i];
        for (int j = n; j < 2 * n; ++j)
        {
            a[i][j] /= temp;
        }
    }

    cout << "\nThe inverse of the matrix is:\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = n; j < 2 * n; ++j)
        {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }   

    return 0;
}
