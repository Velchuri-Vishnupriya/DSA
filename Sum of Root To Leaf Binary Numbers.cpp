//T.C : O(n)
//S.C : O(h) h = height of tree (Recurssion stack space)
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
class Solution {
public:
int solve(TreeNode* root, int current){
    if(!root) return 0;

    current = current*2 + root->val;

    if(!root-> left && !root->right) return current;

   return solve(root->left, current) + solve(root->right,current);
}
    int sumRootToLeaf(TreeNode* root) {
        return solve(root, 0);
        }
};
