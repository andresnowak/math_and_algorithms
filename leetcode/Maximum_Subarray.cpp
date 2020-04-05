/*
@ Name: Andres Nowak
@ Date: Fri Apr  3 10:05:06 CST 2020
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

int sum(auto start, auto end)
{
    int suma = 0;
    for (auto itr = start; itr != end; itr++)
    {
        suma += *itr;
        cout << *itr << endl;
    }
    cout << suma << endl;
    return suma;
}

int maxSubArray1(vector<int> &nums)
{ //TLE: TIME LIMIT EXCEEDED
    //int biggest = -2147483648; // lowest int
    int biggest = nums[0];

    for (int i = 1; i <= (int)nums.size(); ++i)
    {
        for (int j = 0; j <= (int)nums.size() - i; ++j)
        {
            int suma = 0;
            suma = accumulate(nums.begin() + j, nums.begin() + j + i, suma);

            if (suma > biggest)
            {
                biggest = suma;
            }
        }
    }

    return biggest;
}

int maxSubArray(vector<int> &nums) // algoritmo de kanade
{
    int max_sum = nums[0];
    int current_sum = 0;

    for (int x : nums)
    {
        current_sum = max(x, current_sum + x);
        max_sum = max(current_sum, max_sum);
    }

    return max_sum;
}

int main()
{
    vi nums = {1, 2};
    cout << maxSubArray(nums) << endl;
}
