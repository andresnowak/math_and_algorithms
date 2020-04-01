/*
@ Name: Andres Nowak
@ Date: Tue Mar 31 20:26:09 CST 2020
*/

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

vector<bool> primes(ll n)
{
    vector<bool> primes(n + 1, true);

    primes[0] = primes[1] = false;

    ll sum = 0;

    for (ll i = 2; i * i <= n; i++)
    {
        if (primes[i])
        {
            for (ll j = i * i; j <= n; j += i)
            {
                primes[j] = false;
            }
        }
    }

    return primes;
}

void sums(vector<ll> values)
{
    vector<bool> prime = primes(1000000);

    ll sum = 0;
    ll size = prime.size();

    vector<ll> sumas(1000000);

    for (ll i = 0; i <= size; i++)
    {
        if (prime[i])
        {
            sum += i;
        }

        sumas[i] = sum;
    }

    for (ll x : values)
    {
        cout << sumas[x] << endl;
    }
}

int main()
{
    ll n_tests;

    cin >> n_tests;

    vector<ll> values(n_tests);

    for (ll i = 0; i < n_tests; i++)
    {
        cin >> values[i];
    }

    sums(values);
}
