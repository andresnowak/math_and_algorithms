/*
@ Name: Andres Nowak
@ Date: Sat Apr  4 10:23:34 CST 2020
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

void moveZeroes(vector<int> &nums)
{
    int i = 0;

    for (int j = 1; j < (int)nums.size(); ++j)
    {
        if (nums[i] == 0 and nums[j] != 0)
        {
            swap(nums[i], nums[j]);
        }
        if (nums[i] != 0)
        {
            i++;
        }
    }
}

int main()
{
    vi nums = {0, 1, 0, 3, 0, -12, 0};

    moveZeroes(nums);

    for (int x : nums)
    {
        cout << x << endl;
    }
}
