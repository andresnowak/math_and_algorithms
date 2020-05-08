/*
@ Name: Andres Nowak
@ Date: Wed May  6 18:02:48 CDT 2020
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

double myPow(double a, int b) // O(n) time, O(1) space
{                             // recursive power
    if (b == 0)
    {
        return 1;
    }

    double res = myPow(a, b / 2);
    //we execute first the callbacks and the this ifs, so what goes first is last and what goes last goes first
    if (b % 2)
    {
        if (b > 0)
        {
            return res * res * a;
        }
        else
        {
            return (res * res) / a;
        }
    }
    else
    {
        return res * res;
    }
}

double myPow2(double a, int n) // O(n) time, O(1) space
{                              // bitmasks
    double result = 1;

    int b = abs(n);

    while (b > 0)
    {
        cout << b << endl;
        if (b & 1)
        {
            result = result * a;
        }

        a *= a;

        b >>= 1;
    }

    if (n < 0)
    {
        result = 1 / result;
    }

    return result;
}

int main()
{
}
