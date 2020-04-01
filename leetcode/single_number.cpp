/*
@ Name: Andres Nowak
@ Date: Wed Apr  1 11:59:23 CST 2020
*/
#include <bits/stdc++.h>

#define for_number(start, end) for (; start < end; start++)
#define for_iter(a, vect) for (a : vect)
#define for_map(a, mapa) for (&a : mapa)

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pi;

using namespace std;

int singleNumber(vector<int> &nums)
{
    // find a number that is not repeated twice

    map<ll, ll> numbers;

    for_iter(ll x, nums)
    {
        numbers[x]++;
    }

    for (auto const &x : numbers)
    {
        if (x.second == 1)
        {
            return x.first;
        }
    }

    return -1;
}

int singleNumberBetterSolution(vector<int> &nums)
{
    /* example 1 xor 0 = 1 1 xor 2 = 3 y despues 3 xor 2 = 1, creo que solo funciona con numeros pares y que uno no se repita, si no que uno no se repita y los otros solo una vez se repiten
    */

    ll a = 0;

    for_iter(ll x, nums)
    {
        a ^= x;
    }

    return a;
}

int main()
{
    vector<int> h = {1, 2, 2};
    cout << singleNumberBetterSolution(h) << endl;
}
