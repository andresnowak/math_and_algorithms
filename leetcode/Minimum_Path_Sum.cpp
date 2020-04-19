/*
@ Name: Andres Nowak
@ Date: Sat Apr 18 22:31:55 CDT 2020
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

//dp usando el orden de una diagonal de una matriz
int minPathSum(vector<vector<int>> &grid)
{
    int n, m, j, diag;

    n = grid.size();

    if (n == 0)
        return 0;

    m = grid[0].size();

    if (m == 0)
        return 0;

    diag = n + m - 1; // como en el primer ejemplo son 5 diagonales

    for (int d = 1; d < diag; d++)
    {
        for (int i = 0; i < n; i++)
        {
            j = d - i;

            if (j >= 0 and j < m)
            {
                if (i == 0)
                {
                    grid[i][j] += grid[i][j - 1];
                }
                else if (j == 0)
                {
                    grid[i][j] += grid[i - 1][j];
                }
                else
                {
                    grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
                }
            }
        }
    }

    return grid[n - 1][m - 1];
}

//dp
int minPathSum2(vector<vector<int>> &g)
{

    int m = g.size();
    int n = g[0].size();
    int dp[m][n];

    for (int i = 0; i < g.size(); i++)
    {
        for (int j = 0; j < g[i].size(); j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = g[i][j];
            }
            else if (i == 0)
            {
                dp[i][j] = g[i][j] + dp[i][j - 1];
            }
            else if (j == 0)
            {
                dp[i][j] = g[i][j] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = g[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m - 1][n - 1];
}

int main()
{
}
