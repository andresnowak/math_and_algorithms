/*
@ Name: Andres Nowak
@ Date: Sat Apr 25 13:44:15 CDT 2020
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

bool canJump(vector<int> &nums) // O(n) time O(1) space
{
    int max_reach = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] + i > max_reach)
        {
            max_reach = nums[i] + i;
        }
        if (max_reach == i)
        {
            break;
        }
    }

    return max_reach >= nums.size() - 1;
}

int main()
{
}
