/*
@ Name: Andres Nowak
@ Date: Sun Mar 29 15:25:37 CST 2020
*/

#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(vector<int> &list)
{
    for (int i = 1; i < int(list.size()); i++)
    {
        int key = list[i];

        int j = i - 1;

        while (j > 0 and list[j] > key)
        {
            list[j + 1] = list[j];

            j--;
        }

        list[j + 1] = key;
    }
}

int main()
{
    vector<int> list = {1, 5, 3, 2, 4};

    insertion_sort(list);

    for (auto itr = list.begin(); itr != list.end(); itr++)
    {
        cout << *itr << endl;
    }
}
