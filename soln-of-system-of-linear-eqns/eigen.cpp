/* Finding largest Eigen value and corresponding vector by Power method. */

#include <iostream>
#include <cfloat> /* for FLT_MIN */

using namespace std;

int main()
{
    int n;
    cout << "Enter the order of the matrix: ";
    cin >> n;

    float a[n][n], x[n], y[n], d[n], z[n] = {0};

    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> a[i][j];
        }
    }

    cout << "Enter the elements of the vector:\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> x[i];
    }

    float zmax, dmax;
    do 
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                z[i] += a[i][j] * x[j];
            }
        }

        zmax = FLT_MIN;
        for (int i = 0; i < n; ++i)
        {
            if (z[i] > zmax) zmax = z[i];
        }

        for (int i = 0; i < n; ++i)
        {
            y[i] = z[i] / zmax;
        }

        for (int i = 0; i < n; ++i)
        {
            d[i] = y[i] - x[i];
        }

        dmax = FLT_MIN;
        for (int i = 0; i < n; ++i)
        {
            if (d[i] > dmax) dmax = d[i];
        }

        for (int i = 0; i < n; ++i)
        {
            x[i] = y[i];
        }  
    } while (dmax > 0.0001);

    cout << "\nLargest Eigen value: " << zmax << '\n';
    cout << "Corresponding Eigen vector:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << y[i] << '\n';
    }

    return 0;
}
