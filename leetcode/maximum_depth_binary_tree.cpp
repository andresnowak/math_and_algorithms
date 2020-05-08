/*
@ Name: Andres Nowak
@ Date: Wed May  6 17:34:22 CDT 2020
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

int depth(TreeNode *root) // O(n^2) time, O(n^2) space ?
{
    if (root == NULL)
    {
        return 0;
    }

    int right = depth(root->right);
    int left = depth(root->left);

    return max(right, left) + 1;
}

int maxDepth(TreeNode *root)
{
    return depth(root);
}

int main()
{
}
