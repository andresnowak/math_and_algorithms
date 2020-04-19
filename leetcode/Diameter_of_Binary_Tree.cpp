/*
@ Name: Andres Nowak
@ Date: Sat Apr 11 22:40:28 CDT 2020
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    int ans;

    int height(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int rights = height(root->right);
        int lefts = height(root->left);

        ans = max(ans, lefts + rights + 1); // si no se pone el +1 y ans = 0 no es necesario el ans - 1

        return max(lefts, rights) + 1; //porque puede regresar este valor en recursividad
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        ans = 1; // se puede ans = 0
        height(root);
        return ans - 1; // se puede solo ans si ans = 0
    }
};

int main()
{
}
