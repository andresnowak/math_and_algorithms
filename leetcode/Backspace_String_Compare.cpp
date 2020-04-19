/*
@ Name: Andres Nowak
@ Date: Thu Apr  9 18:16:20 CDT 2020
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

bool backspaceCompare(string S, string T)
// Time : O(M + N) space : 0(1) M size of S and N size of T

/* comenzamos derecha izquierda para poder hacer las eliminaciones facilmente
ya que aunque elimines un valor sigues apuntando a un valor y val eliminar
siempre el valor correcto porque en cada iteracion antes de eliminar otro valor
nos movemos de posicion y asi no se tien que preocupar de la posicion*/
{
    int erase = 0;

    int sizeS = S.length();
    int sizeT = T.length();

    for (int i = sizeS - 1; i >= 0; i--)
    {
        if (S[i] == '#')
        {
            S.erase(i, 1);
            erase++;
        }
        else if (erase > 0)
        {
            S.erase(i, 1);
            erase--;
        }
    }

    erase = 0;

    for (int i = sizeT - 1; i >= 0; i--)
    {
        if (T[i] == '#')
        {
            T.erase(i, 1);
            erase++;
        }
        else if (erase > 0)
        {
            T.erase(i, 1);
            erase--;
        }
    }

    return S == T;
}

bool backspaceCompare2(string S, string T)
{
    // Time : O(M + N) space : 0(N + M) M size of S and N size of T
    // solucion rapida

    stack<char> S_stack;
    stack<char> T_stack;

    for (char x : S)
    {
        if (x == '#' and S_stack.size() > 0)
        {
            S_stack.pop();
        }
        else if (x != '#')
        {
            S_stack.push(x);
        }
    }

    for (char x : T)
    {
        if (x == '#' and T_stack.size() > 0)
        {
            T_stack.pop();
        }
        else if (x != '#')
        {
            T_stack.push(x);
        }
    }

    return S_stack == T_stack;
}

int main()
{
}
