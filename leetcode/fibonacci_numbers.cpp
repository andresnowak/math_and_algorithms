/*
@ Name: Andres Nowak
@ Date: Tue May  5 23:29:49 CDT 2020
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

int recursiveFb(vector<int> &fibonacci, int pos, int &N)
{
    if (pos == N)
    {
        return fibonacci[pos];
    }

    fibonacci.push_back(fibonacci[pos] + fibonacci[pos - 1]);

    return recursiveFb(fibonacci, pos + 1, N);
}

int fib(int N) // O(n) time, O(n) space
{              // recursive and dp?
    vector<int> fibonacci = {0, 1};

    if (fibonacci.size() > N)
    {
        return fibonacci[N];
    }

    return recursiveFb(fibonacci, 1, N);
}
// ------------------------
int fib2(int N) // golden ratio formula to calculate the Nth Fibonacci number
{               // O(1) time and O(1) space
    float golden_ratio = (1.0 + (pow(5.0, 0.5))) / 2.0;
    cout << pow(5.0, 0.5) << endl;

    return (pow(golden_ratio, float(N)) + 1.0) / pow(5.0, 0.5);
}
// -------------------------
int recursiveFb3(int prev1, int prev2, int current, int pos, int &N) // O(n) time O(1) space
{
    if (pos == N)
    {
        return current;
    }

    prev1 = prev2;
    prev2 = current;
    current = prev1 + prev2;

    return recursiveFb3(prev1, prev2, current, pos + 1, N);
}

int fib3(int N) // O(n) time, O(1) space
{
    int prev1 = 0, prev2 = 1, current = 1;

    if (N == 0)
    {
        return prev1;
    }
    else if (N == 1)
    {
        return prev2;
    }

    return recursiveFb3(prev1, prev2, current, 2, N);
}

int main()
{
}
