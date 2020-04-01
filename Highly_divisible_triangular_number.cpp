/*
@ Name: Andres Nowak
@ Date: Tue Mar 31 17:24:47 CST 2020
*/

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

vector<bool> primes(ll n)
{
    vector<bool> is_prime(n + 1, true);

    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= n; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    return is_prime;
}

map<ll, ll> prime_factors(vector<bool> prime, ll n)
{
    map<ll, ll> factorization; // a map to know how many times a number is to know the exponent and use that to calculate the total factors

    ll size_primes = prime.size();

    for (long long i = 0; i < size_primes; i++)
    {
        if (prime[i])
        {
            if (i * i > n)
            {
                break;
            }

            while (n % i == 0)
            {
                factorization[i]++;

                n /= i;
            }
        }
    }

    if (n > 1)
    {
        factorization[n]++;
    }

    return factorization;
}

ll factors(ll n, ll biggest_factor)
{
    ll total_factors = 1;

    vector<bool> prime = primes(n);

    ll triangle_numbers = 0;

    for (int i = 1; i <= n; i++)
    {
        triangle_numbers += i;

        total_factors = 1;

        map<ll, ll> factors = prime_factors(prime, triangle_numbers);

        for (auto const &x : factors)
        {
            total_factors *= (x.second + 1); // multiplicar los exponentes de cada primo factor  + 1 osea cuantas veces se repite el primo factor en las divisiones del numero.
        }

        if (total_factors > biggest_factor)
        {
            return triangle_numbers;
        }
    }

    return -1;
}

int main()
{
    int n_tests;

    cin >> n_tests;

    vector<int> results(n_tests);

    ll value;

    for (int i = 0; i < n_tests; i++)
    {
        cin >> value;

        results[i] = factors(1000000000, value);
    }

    for (ll x : results)
    {
        cout << x << endl;
    }
}
