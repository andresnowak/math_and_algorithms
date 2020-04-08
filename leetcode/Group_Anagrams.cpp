/*
@ Name: Andres Nowak
@ Date: Mon Apr  6 12:49:39 CDT 2020
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

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> anagrams;

    int count[26];

    for (string x : strs)
    {
        //string keys_a = x;
        //sort(keys_a.begin(), keys_a.end()); // O(m * log(m))

        fill(begin(count), end(count), 0);
        string keys_a(26, '0');

        for (char y : x)
        {
            count[int(y - 'a')]++;

            keys_a[int(y - 'a')] = count[int(y - 'a')];
        } // O(m)

        if (anagrams.find(keys_a) == anagrams.end())
        {
            anagrams[keys_a] = {x};
        }
        else
        {
            anagrams[keys_a].push_back(x);
        }
    }

    vector<vector<string>> anagram;

    for (auto const &x : anagrams)
    {
        anagram.push_back(x.second);
    }
    return anagram; // O(m * n) o la otra otra solucion O((m * log(m)) * n) y espacio O(n)
}

int main()
{
    vector<string> words = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = groupAnagrams(words);

    for (auto const &x : result)
    {
        for (string y : x)
        {
            cout << y << ' ';
        }
        cout << '\n';
    }
}
