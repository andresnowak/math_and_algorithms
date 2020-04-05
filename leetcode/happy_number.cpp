/*
@ Name: Andres Nowak
@ Date: Thu Apr  2 15:02:09 CST 2020
*/
#include <bits/stdc++.h>

#define for_number(start, end) for (int i = start; i < end; ++i)
#define for_iter(a, vect) for (a : vect)
#define for_map(a, mapa) for (auto const &a : mapa)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pi;

bool isHappy(int n)
{
    string num = to_string(n);
    int sum = 0;

    while (true)
    {
        sum = 0;

        /*for (char x : num)
        {
            sum += pow(int(x - '0'), 2);
        }
        */

        while (n != 0)
        {
            sum += (n % 10) * (n % 10);

            n /= 10;
            // en vez de recorrer caracteres podemos recorrer cada numero usando modulo 10 y luego dividiendo el numero entre 10 para pasar al siguiente numero
        }

        if (sum == 1)
        {
            return true;
        }

        else if (sum == 4) /* deduci al hacer ejemplos que si en algun punto 
        tienes 37 en la suma de cuadrados significa que no es un happy number 
        osea la suma nunca va a dar 1.
        4 es quien crea la regla de si un numero no es happy*/
        {
            return false;
        }

        n = sum;
    }
}

bool isHappy2(int n)
{
    /* Si se queda en un loop cuando no es happy significa que en algun punto un numero se va a repetir.*/

    unordered_map<int, int> sums;

    int sum = 0;

    while (true)
    {
        sum = 0;

        while (n) // es lo mismo que n != 0 porque 0 es false
        {
            sum += (n % 10) * (n % 10);

            n /= 10;
        }

        sums[sum]++;

        if (sums[sum] == 2)
        {
            return false;
        }
        else if (sum == 1)
        {
            return true;
        }

        n = sum;
    }
}

/* int can only have 10 digits each one with 9
so it would be 10*9^2 = 810 biggest number, solo se suman */
int f(int n) // log(N)
{
    int sum = 0;

    while (n) // es lo mismo que n != 0 porque 0 es false
    {
        sum += (n % 10) * (n % 10);

        n /= 10;
    }

    return sum;
}

bool isHappy3(int n) // maximo puede solo haber 19 ciclos ya despues se repite un numero o da 1
{
    unordered_set<int> sums;

    while (true)
    {
        n = f(n);

        if (sums.count(n) == 1)
        {
            return false;
        }

        sums.insert(n);

        if (n == 1)
        {
            return true;
        }
    }
}

int main()
{
    cout << isHappy3(19) << endl;
    cout << isHappy3(22) << endl;
}
