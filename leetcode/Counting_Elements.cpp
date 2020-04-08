/*
@ Name: Andres Nowak
@ Date: Tue Apr  7 13:51:46 CDT 2020
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

int countElements(vector<int> &arr)
{
    unordered_set<int> arrs;
    int total = 0;

    for (int x : arr)
    {
        arrs.insert(x);
    }
    for (int x : arr)
    {
        if (arrs.count(x + 1) == 1)
        {
            total++;
        }
    }
    return total;
}

int main()
{
}
