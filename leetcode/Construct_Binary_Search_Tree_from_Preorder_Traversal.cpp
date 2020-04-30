/*
@ Name: Andres Nowak
@ Date: Mon Apr 20 14:54:30 CDT 2020
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

TreeNode *buildTree(vector<int> &preorder, int left, int right)
{
    if (left > right)
    {
        return nullptr;
    }

    TreeNode *root = new TreeNode(preorder[left]);

    if (left == right)
    {
        return root;
    }

    int index = left + 1;

    while (index <= right and preorder[index] < preorder[left])
    {
        index++;
    }

    root->left = buildTree(preorder, left + 1, index - 1);
    root->right = buildTree(preorder, index, right);

    return root;
}

TreeNode *bstFromPreorder(vector<int> &preorder)
{
    return buildTree(preorder, 0, preorder.size() - 1);
}

int main()
{
}
