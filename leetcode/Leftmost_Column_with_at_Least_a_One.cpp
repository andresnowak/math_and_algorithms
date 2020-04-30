/*
@ Name: Andres Nowak
@ Date: Wed Apr 22 00:02:05 CDT 2020
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

int leftMostColumnWithOne(BinaryMatrix &binaryMatrix)
{ // O(r + c) time
    vector<int> dimensions = binaryMatrix.dimensions();

    int rows = dimensions[0];
    int cols = dimensions[1];

    if (rows == 0 or cols == 0)
    {
        return -1;
    }

    int result = -1;

    int r = 0, c = cols - 1;

    while (r < rows and c >= 0)
    {
        if (binaryMatrix.get(r, c) == 1)
        {
            result = c;

            c--;
        }
        else
        {
            r++;
        }
    }

    return result;
}

int main()
{
}
