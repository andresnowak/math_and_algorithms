/*
@ Name: Andres Nowak
@ Date: Fri May  8 17:47:30 CDT 2020
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

struct Node
{
    int val;
    Node *next;
    Node(int x) : val(x), next(NULL) {}
};

class MyLinkedList
{
public:
    /** Initialize your data structure here. */
    Node *head;
    Node *tail;

    int size;

    MyLinkedList()
    {
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index)
    {
        if (index >= this->size or index < 0)
        {
            return -1;
        }

        int count = 0;

        Node *tmp = head;

        while (tmp)
        {
            if (count++ == index)
            {
                return tmp->val;
            }

            tmp = tmp->next;
        }

        return -1;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val)
    {
        Node *current = new Node(val);

        if (this->head == NULL)
        {
            this->head = current;
            this->tail = current;
        }
        else
        {
            current->next = this->head;
            this->head = current;
        }

        this->size++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val)
    {
        Node *current = new Node(val);

        if (this->tail == NULL)
        {
            this->head = current;
            this->tail = current;
        }
        else
        {
            this->tail->next = current;
            this->tail = current;
        }

        this->size++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val)
    {
        if (index > this->size)
        {
            return;
        }
        else if (index == this->size)
        {
            this->addAtTail(val);

            return;
        }
        else if (index == 0)
        {
            this->addAtHead(val);

            return;
        }

        int count = 0;

        Node *tmp = head;

        while (tmp)
        {
            if (count++ == index - 1)
            {
                Node *addp = new Node(val);

                addp->next = tmp->next;
                tmp->next = addp;

                break;
            }

            tmp = tmp->next;
        }

        this->size++;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        if (index >= this->size)
        {
            return;
        }
        if (index == 0)
        {
            this->head = this->head->next;
        }
        else
        {
            int count = 0;

            Node *tmp = this->head;

            for (int i = 0; i < index - 1; i++)
            {
                tmp = tmp->next;
            }

            tmp->next = tmp->next->next;

            if (index == this->size - 1)
            {
                this->tail = tmp;
            }
        }

        this->size--;
    }
};

int main()
{
}
