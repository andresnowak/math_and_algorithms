/*
@ Name: Andres Nowak
@ Date: Tue May  5 21:59:03 CDT 2020
*/
#include <bits/stdc++.h>

#define for_number(start, end) for (auto i = start; i < end; i++)
#define for_iter(a, vect) for (a : vect)
#define for_map(mapa) for (auto const &a : mapa)
#define MP make_pair
#define PB push_back
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pi;

void pascalTriangle(int i, int j, vector<vector<int>> &pascal)
{
    if (j == i or j == 0)
    {
        pascal[i][j] = 1;

        if (j == i)
        {
            return;
        }
    }
    else
    {
        pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
    }

    return pascalTriangle(i, j + 1, pascal);
}

vector<int> getRow(int rowIndex)
{
    vector<vector<int>> pascal;

    for (int i = 0; i <= rowIndex; i++)
    {
        vector<int> row(i + 1, 0);
        pascal.push_back(row);

        pascalTriangle(i, 0, pascal);
    }

    return pascal[rowIndex];
}

int main()
{
}
