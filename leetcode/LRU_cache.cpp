/*
@ Name: Andres Nowak
@ Date: Fri Apr 24 13:02:24 CDT 2020
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

class LRUCache
{
private:
    int _capacity;

    list<int> _keys;
    unordered_map<int, pair<int, list<int>::iterator>> _map;

public:
    LRUCache(int capacity) : _capacity(capacity)
    {
    }

    int get(int key)
    {

        if (_map.find(key) != _map.end())
        {
            _keys.erase(_map[key].second);
            _keys.push_front(key);
            _map[key].second = _keys.begin();

            return _map[key].first;
        }

        return -1;
    }

    void put(int key, int value)
    {
        if (_map.find(key) != _map.end())
        {
            _keys.erase(_map[key].second);
            _keys.push_front(key);
            _map[key] = {value, _keys.begin()};
        }
        else
        {
            if (_keys.size() == _capacity)
            {
                _map.erase(_keys.back());
                _keys.pop_back();
            }
            _keys.push_front(key);
            _map[key] = {value, _keys.begin()};
        }
    }
};

int main()
{
}
