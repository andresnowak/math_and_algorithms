/*
@ Name: Andres Nowak
@ Date: Wed Apr 15 21:17:37 CDT 2020
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

vector<int> productExceptSelf(vector<int> &nums) // O(n) time O(1) size
{
    int size = nums.size();

    vector<int> results(size); //doesnt count result to size

    results[0] = 1;
    for (int i = 1; i < size; i++)
    {
        results[i] = results[i - 1] * nums[i - 1];
    }

    int right_product = nums[size - 1];

    for (int i = size - 2; i >= 0; i--)
    {
        results[i] *= right_product;

        right_product *= nums[i];
    }

    return results;
}

vector<int> productExceptSelf2(vector<int> &nums) // O(n) time O(2n) size
{
    int size = nums.size();

    vector<int> results(size); //doesnt count result to size
    vector<int> left(size);
    vector<int> right(size);

    left[0] = 1;
    for (int i = 1; i < size; i++)
    {
        left[i] = left[i - 1] * nums[i - 1];
    }

    right[size - 1] = 1;
    for (int i = size - 2; i >= 0; i--)
    {
        right[i] = right[i + 1] * nums[i + 1];
    }

    for (int i = 0; i < size; i++)
    {
        results[i] = left[i] * right[i];
        cout << right[i] << endl;
        cout << left[i] << endl;
    }

    return results;
}

int main()
{
}
