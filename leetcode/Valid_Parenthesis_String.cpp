/*
@ Name: Andres Nowak
@ Date: Thu Apr 16 19:17:28 CDT 2020
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

bool checkValidString(string s) {
    int balance = 0;
    
    if(s.length() == 0){
        return true;
    }
    
    for(char x : s){
        if(x == ')'){
            balance--;
        }
        else{
            balance++;
        }
        
        if(balance < 0){
            return false;
        }
    }
        
    balance = 0;
        
    for(int i = s.length() - 1; i >= 0; i--){
        if(s[i] == '('){
            balance--;
        }
        else{
            balance++;
        }

        if(balance < 0){
            return false;
        }
    }

    return true;
}

bool checkValidString(string s) {
    int lo = 0, hi = 0;

    for(char x : s){
        if(x == '(') lo++; // la cantidad de open brackets
        else lo--;
        
        if(x != ')') hi++;
        else hi--;
        
        if(hi < 0) return false;// hi es nuestro balance si es negativo, siginifica que no se puede balancear
        
        lo = max(lo, 0);
    }
    
    return lo == 0;
}

int main() {

}
