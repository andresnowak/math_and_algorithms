/*
@ Name: Andres Nowak
@ Date: Sat Apr 18 01:21:23 CDT 2020
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

// dfs solution, depth-first-search
//tambien se puede hacer con bfs breadth-first-search, que seria o podia ser iterativo

void getisland(vector<vector<char>> &grid, int row, int col, int &rows, int &cols)
{
    if (row < 0 or col < 0 or col >= cols or row >= rows or grid[row][col] != '1')
    {
        return;
    }

    grid[row][col] = '2';

    getisland(grid, row + 1, col, rows, cols); //up
    getisland(grid, row - 1, col, rows, cols); //down
    getisland(grid, row, col + 1, rows, cols); //right
    getisland(grid, row, col - 1, rows, cols); //left

    //quien sabe porque con ++row no funciona si deberia ser lo mismo
    //row++ no debe funcionar pero ++row si
}

public:
int numIslands(vector<vector<char>> &grid) //time O(n) worst case recorre una celda 5 veces, Space O(n*m) o si no nos importa la memoria de recursiva O(1)

{
    int n = grid.size();
    if (n == 0)
    {
        return 0;
    }
    int m = grid[0].size();

    int islands = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (grid[i][j] == '1')
            {
                getisland(grid, i, j, n, m);

                islands++;
            }
        }
    }

    return islands;
}

int main()
{
}
