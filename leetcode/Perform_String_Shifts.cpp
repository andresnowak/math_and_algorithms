/*
@ Name: Andres Nowak
@ Date: Tue Apr 14 15:16:23 CDT 2020
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

string stringShift(string s, vector<vector<int>> &shift)
{
    int values = 0;

    for (auto const &x : shift)
    {
        values += x[0] == 0 ? x[1] : -x[1];
    }

    deque<char> strings;

    for (char x : s)
    {
        strings.push_back(x);
    }

    for (int i = 0; i < abs(values); i++)
    {
        if (values < 0)
        {
            char tmp = strings.back();

            strings.pop_back();
            strings.push_front(tmp);
        }
        else
        {
            char tmp = strings.front();

            strings.pop_front();
            strings.push_back(tmp);
        }
    }

    s = "";

    for (char x : strings)
    {
        s += x;
    }

    return s;
}

int main()
{
}
