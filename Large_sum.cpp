/*
@ Name: Andres Nowak
@ Date: Tue Mar 31 19:23:31 CST 2020
*/

#include <bits/stdc++.h>
#include <string>

using namespace std;

int main()
{
    int n = 100;

    string number;

    unsigned long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> number;
        sum += stoll(number.substr(0, 9)); //stoll to convert a string to long long instead of using stoi we use stoll
    }

    cout << sum << endl;
}
