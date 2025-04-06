//T.C: O(2*n)
//S.C: O(maxD)
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
unordered_map<int,int> mp;
int maxD=0;
TreeNode* LCA(TreeNode* root){
    if(!root || mp[root->val]==maxD){
        return root;
    }
    TreeNode* l=LCA(root->left);
    TreeNode* r=LCA(root->right);
    
    if(l && r)return root;
    return l!=NULL ?l:r;
}

void depth(TreeNode* root,int d){
    if(!root) return;
    maxD=max(maxD,d);
    mp[root->val]=d;
    depth(root->left,d+1);
    depth(root->right,d+1);
}
    TreeNode* lcaDeepestLeaves(TreeNode* root) { 
       depth(root,0);
       return LCA(root);
    }
};

//Approach-2 (Using 1 Pass Solution)
//T.C : O(n)
//S.C : O(maxDepth) System stack space
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
pair<int,TreeNode*> solve(TreeNode* root){
    //pair{depth,LCA}
    if(root==NULL){
        return {0,NULL};
        }
auto l=solve(root->left);
auto r=solve(root->right);

if(l.first ==r.first){
    return {l.first+1,root};
}
else if(l.first>r.first){
    return {l.first+1,l.second};
}
else{
    return {r.first+1,r.second};
    }
}
    TreeNode* lcaDeepestLeaves(TreeNode* root) { 
     return solve(root).second;
    }
};
