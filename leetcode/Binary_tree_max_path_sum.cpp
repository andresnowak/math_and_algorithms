/*
@ Name: Andres Nowak
@ Date: Wed Apr 29 18:18:56 CDT 2020
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

int maxPathSum(TreeNode *root)
{
    int h = INT_MIN;

    return mpSum(root, h);
}

int mpSum(TreeNode *root, int &h)
{
    if (root == nullptr)
    {
        return INT_MIN;
    }

    int h1 = INT_MIN;
    int h2 = INT_MIN;

    int d1 = mpSum(root->left, h1);
    int d2 = mpSum(root->right, h2);

    h = max({h1, h2, 0}) + root->val;

    return max({d1, d2, max(h1, 0) + max(h2, 0) + root->val});
}

int main()
{
}
