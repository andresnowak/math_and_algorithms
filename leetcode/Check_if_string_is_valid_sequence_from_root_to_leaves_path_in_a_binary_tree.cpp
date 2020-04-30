/*
@ Name: Andres Nowak
@ Date: Thu Apr 30 10:22:24 CDT 2020
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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool isValidSequence(TreeNode *root, vector<int> &arr)
    {
        if (!root)
            return arr.size() == 0;

        return isValid(root, arr, 0);
    }

    bool isValid(TreeNode *root, vector<int> &arr, int idx)
    {
        if (root->val != arr[idx])
            return false;

        if (idx == arr.size() - 1)
            return !root->left and !root->right;

        return ((root->left and isValid(root->left, arr, idx + 1)) or
                (root->right and isValid(root->right, arr, idx + 1)));
    }
};

int main()
{
}
