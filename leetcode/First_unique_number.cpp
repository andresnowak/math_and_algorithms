/*
@ Name: Andres Nowak
@ Date: Tue Apr 28 22:34:43 CDT 2020
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

class FirstUnique
{
    unordered_map<int, list<int>::iterator> _map;
    list<int> _keys;

public:
    FirstUnique(vector<int> &nums)
    {
        for (int n : nums)
        {
            add(n);
        }
    }

    int showFirstUnique()
    {
        if (_keys.size())
        {
            return _keys.front();
        }
        else
        {
            return -1;
        }
    }

    void add(int value)
    {
        if (_map.find(value) != _map.end())
        { // key present
            list<int>::iterator it = _map[value];

            if (it != _keys.end())
            { // key in list
                _keys.erase(it);
                _map[value] = _keys.end();
            }
        }
        else
        {
            _keys.push_back(value);
            list<int>::iterator it = _keys.end();
            it--;

            _map[value] = it;
        }
    }
};

int main()
{
}
