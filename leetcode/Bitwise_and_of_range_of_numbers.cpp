/*
@ Name: Andres Nowak
@ Date: Thu Apr 23 16:42:22 CDT 2020
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

int rangeBitwiseAnd(int m, int n) // O(n) time O(1) space
{
    int answer = m;

    int s = 1;

    while (m != n)
    {
        m >>= 1; // division by 2
        n >>= 1;

        s <<= 1; // multiply by 2
    }

    cout << s;
    return m * s;
}

int main()
{
}
