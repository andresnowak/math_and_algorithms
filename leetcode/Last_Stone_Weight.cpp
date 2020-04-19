/*
@ Name: Andres Nowak
@ Date: Sun Apr 12 14:58:00 CDT 2020
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

int lastStoneWeight(vector<int> &stones)
{
    make_heap(stones.begin(), stones.end());
    int x, y;

    while (stones.size() > 1)
    {
        y = stones.front();
        pop_heap(stones.begin(), stones.end());
        stones.pop_back();

        x = stones.front(); // x <= y, never x is bigger
        pop_heap(stones.begin(), stones.end());
        stones.pop_back();

        if (x != y)
        {
            stones.push_back(y - x);
            push_heap(stones.begin(), stones.end());
        }
    }

    /*if(stones.size() == 0)
    {
        return 0;
    }
    else
    {
        return stones.front();
    }*/

    return accumulate(stones.begin(), stones.end(), 0);
}

int main()
{
}
