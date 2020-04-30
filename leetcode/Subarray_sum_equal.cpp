/*
@ Name: Andres Nowak
@ Date: Wed Apr 22 12:55:44 CDT 2020
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

int subarraySum(vector<int> &nums, int k) //O(n) time O(n) space
{
    // STL map to store number of subarrays
    // starting from index zero having
    // particular value of sum.
    unordered_map<int, int> prev_sum;

    int res = 0;

    int current_sum = 0;

    for (int x : nums)
    {
        // Add current element to sum so far.
        current_sum += x;

        // If currsum is equal to desired sum,
        // then a new subarray is found. So
        // increase count of subarrays.
        if (current_sum == k)
        {
            res++;
        }

        // currsum exceeds given sum by currsum
        //  - sum. Find number of subarrays having
        // this sum and exclude those subarrays
        // from currsum by increasing count by
        // same amount.
        if (prev_sum.find(current_sum - k) != prev_sum.end())
        {
            res += prev_sum[current_sum - k];
        }

        prev_sum[current_sum]++;
    }

    return res;
}

int subarrraySum(vector<int> &nums, int k){
    int size = nums.size();

    int answer = 0;

    int pref = 0;

    unordered_map<int, int> countPref;

    countPref[pref]++;

    for(int r = 0; r < size; r++){

        pref += nums[r];

        int need = pref - k;

        answer += countPref[need];

        countPref[need]++;
    }

    return answer;
}

int main()
{
}
