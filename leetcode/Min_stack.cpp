/*
@ Name: Andres Nowak
@ Date: Fri Apr 10 14:01:21 CDT 2020
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

class MinStack
{
private:
    vector<int> stackn;
    vector<int> smallests;

public:
    /** initialize your data structure here. */

    MinStack()
    {
        stackn = {};
        smallests = {};
    }

    void push(int x)
    {
        stackn.push_back(x);

        if (smallests.size() == 0 or x < *(smallests.end() - 1))
        {
            smallests.push_back(x);
        }
        else
        {
            smallests.push_back(*(smallests.end() - 1));
        }
    }

    void pop()
    {
        stackn.erase(stackn.end() - 1);
        smallests.erase(smallests.end() - 1);
    }

    int top()
    {
        return *(stackn.end() - 1);
    }

    int getMin()
    {
        return *(smallests.end() - 1);
    }
};

class MinStack2
{
private:
    stack<pair<int, int>> stackn;

public:
    /** initialize your data structure here. */

    MinStack()
    {
    }

    void push(int x)
    {
        if (stackn.empty())
        {
            stackn.push(make_pair(x, x));
        }
        else
        {
            int current_min = stackn.top().second;
            stackn.push(make_pair(x, min(x, current_min)));
        }
    }

    void pop()
    {
        stackn.pop();
    }

    int top()
    {
        return stackn.top().first;
    }

    int getMin()
    {
        return stackn.top().second;
    }
};

int main()
{
}
