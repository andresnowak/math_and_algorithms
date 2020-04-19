/*
@ Name: Andres Nowak
@ Date: Wed Apr  8 14:40:09 CDT 2020
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

//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *middleNode1(ListNode *head)
{
    ListNode *ans = head; // new ListNode
    ans = head;

    int val = 1;
    while (ans->next != NULL)
    {
        ans = ans->next;
        val++;
    }

    /*solo lo dividimos entre 2 ya que en el for como 
        estamos siempre apuntando al siguiente valor vamos a apuntar al valor
        segundo del medio y no el primero, por decir que tal si mide 6 la mitad 
        es 3 en este caso hay dos mitades 1 2 3 y 4 5 6 pero nosotros queremos
        el segundo bueno despues de 3 iteraciones no vamos a apuntar a 3 si no
        a cuatro por que estamos accediendo siempre al siguiente valor desde el
        primero*/

    val = ceil(val / 2);

    ans = head;

    for (int i = 0; i < val; i++)
    {
        ans = ans->next;
    }

    return ans;
    [3 4 5]
}

//creo que tiene que ver con el hare and turtle algorithm
ListNode *middleNode(ListNode *head)
{
    /*When traversing the list with a pointer slow, make another pointer fast that traverses twice as fast. When fast reaches the end of the list, slow must be in the middle.*/

    ListNode *fast = head;
    ListNode *slow = head;

    while (fast != NULL and fast->next != NULL)
    {
        /*hacemos dos comprobaciones en el while ya que si el tamano es impar
        quieres acabar cuando el valor next es null porque estas en la posicion
        donde todavia hay valor y el siguiente ya es null y cuando el
        tamano es par quieres acabar cuando el valor donde esta es null 
        porque si accedes al siguiente no puedes acceder porque no hay nada*/

        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

int main()
{
    ListNode *head = *ListNode;

    for (int i = 1; i <= 6; i++)
    {
        head->val = i;
    }

    cout << head->val << endl;
}
