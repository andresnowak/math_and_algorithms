/*
@ Name: Andres Nowak
@ Date: Tue Mar 31 14:48:54 CST 2020
*/

#include <bits/stdc++.h>

typedef long long int ll;

using namespace std;

ll largest_product(vector<vector<int>> matrix)
{
    ll largest = 0;

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            ll horizontal = j < 17 ? matrix[i][j] * matrix[i][j + 1] * matrix[i][j + 2] * matrix[i][j + 3] : 0;

            ll vertical = i < 17 ? matrix[i][j] * matrix[i + 1][j] * matrix[i + 2][j] * matrix[i + 3][j] : 0;

            ll d1 = i >= 3 ? matrix[i][j] * matrix[i + 1][j - 1] * matrix[i + 2][j - 2] * matrix[i + 3][j - 3] : 0;

            ll d2 = i < 17 ? matrix[i][j] * matrix[i + 1][j + 1] * matrix[i + 2][j + 2] * matrix[i + 3][j + 3] : 0;

            if (horizontal > largest)
            {
                largest = horizontal;
            }
            if (vertical > largest)
            {
                largest = vertical;
            }
            if (d1 > largest)
            {
                largest = d1;
            }
            if (d2 > largest)
            {
                largest = d2;
            }
        }
    }

    return largest;
}

int main()
{
    vector<vector<int>> matrix(20, vector<int>(20));

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << largest_product(matrix) << endl;
}
