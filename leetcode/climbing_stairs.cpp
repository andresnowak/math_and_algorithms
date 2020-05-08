/*
@ Name: Andres Nowak
@ Date: Wed May  6 16:49:29 CDT 2020
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

/*
    In the previous approach we are redundantly calculating the result for every step. Instead, we can store the     result at each step in memomemo array and directly returning the result from the memo array whenever that         function is called again.

    In this way we are pruning recursion tree with the help of memomemo array and reducing the size of recursion     tree upto nn.
    */
int climbStairs(int n) // O(n) time, O(n) space
{
    vector<int> memo(n + 1, 0);

    return climb_stairs(0, n, memo);
    ee
}

int climb_stairs(int i, int &n, vector<int> &memo)
{
    if (i > n)
    {
        return 0;
    }
    else if (i == n)
    {
        return 1;
    }

    if (memo[i] > 0)
    {
        return memo[i];
    }

    memo[i] = climb_stairs(i + 1, n, memo) + climb_stairs(i + 2, n, memo);

    return memo[i];
}

int climbStairs2(int n) // O(n) time, O(n) space
{                       // dp
    if (n == 1)
    {
        return 1;
    }

    int dp[n + 1];

    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int climbStairs3(int n) // O(n) time, O(n) space
{                       // fibonacci
    if (n == 1)
    {
        return 1;
    }

    int first = 1;
    int second = 2;

    for (int i = 3; i <= n; i++)
    {
        int third = first + second;

        first = second;
        second = third;
    }

    return second;
}

int main()
{
}
