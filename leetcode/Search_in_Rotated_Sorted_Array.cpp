/*
@ Name: Andres Nowak
@ Date: Sun Apr 19 14:11:44 CDT 2020
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

int search(vector<int> &nums, int target)
{
    if (nums.size() == 0)
    {
        return -1;
    }

    int mid, left, right;

    auto pivot = is_sorted_until(nums.begin(), nums.end());

    if (nums[0] <= target and *(pivot - 1) >= target)
    {
        left = 0;
        right = (pivot - 1) - nums.begin();
    }
    else
    {
        left = (pivot)-nums.begin();
        right = nums.size() - 1;
    }

    while (left <= right)
    {
        mid = (left + right) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }

        if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

int main()
{
}
