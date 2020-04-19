/*
@ Name: Andres Nowak
@ Date: Mon Apr 13 17:02:51 CDT 2020
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

int findMaxLength(vector<int> &nums)
{
    unordered_map<int, int> len = {{0, -1}};

    int max_length = 0;
    int count = 0;

    for (int i = 0; i < (int)nums.size(); i++)
    {
        count += ((nums[i] == 1) ? 1 : -1);

        if (len.find(count) != len.end())
        {
            max_length = max(max_length, i - len[count]);
        }
        else
        {
            len[count] = i;
        }
    }

    return max_length;
}

int main()
{
}
