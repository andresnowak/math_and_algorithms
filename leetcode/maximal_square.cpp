/*
@ Name: Andres Nowak
@ Date: Mon Apr 27 14:57:35 CDT 2020
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

int maximalSquare(vector<vector<char>> &matrix) // O(mn) time O(n) space
{
    //it can be solved recursively but is better dp

    int r = matrix.size();
    if (r == 0)
        return 0;

    int c = matrix[0].size();
    if (c == 0)
        return 0;

    int max_square = 0;

    vector<vector<int>> sol(r, vector<int>(c, 0));

    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            if (i == 0 or j == 0)
            {
                if (matrix[i][j] == '1')
                {
                    sol[i][j] = 1;
                    max_square = max(max_square, sol[i][j]);
                }
            }
            else
            {
                if (matrix[i][j] == '1')
                {
                    sol[i][j] = 1 + min({sol[i - 1][j - 1], sol[i - 1][j], sol[i][j - 1]});
                    max_square = max(max_square, sol[i][j]);
                }
            }
        }
    }

    return max_square * max_square;
}

int main()
{
}
