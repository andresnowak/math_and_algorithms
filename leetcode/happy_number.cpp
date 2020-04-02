/*
@ Name: Andres Nowak
@ Date: Thu Apr  2 15:02:09 CST 2020
*/
#include <bits/stdc++.h>

#define for_number(start, end) for (; start < end; start++)
#define for_iter(a, vect) for (a : vect)
#define for_map(a, mapa) for (&a : mapa)

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pi;

using namespace std;

bool isHappy(int n)
{
    string num = to_string(n);
    int sum = 0;

    while (true)
    {
        sum = 0;

        for (char x : num)
        {
            sum += pow(int(x - '0'), 2);
        }

        if (sum == 1)
        {
            return true;
        }
        else if (sum == 37) /* deduci al hacer ejemplos que si en algun punto 
        tienes 37 en la suma de cuadrados significa que no es un happy number 
        osea la suma nunca va a dar 1*/
        {
            return false;
        }

        num = to_string(sum);
    }
}

int main()
{
    cout << isHappy(19) << endl;
    cout << isHappy(22) << endl;
}
