//T.C : O(n)
//S.C : O(n)
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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*>mp;
        unordered_set<int> st;

        for(auto& d : descriptions){
            int p = d[0];
            int c = d[1];
            int isLeft = d[2];

            if(mp.find(p) == mp.end()){
                mp[p] = new TreeNode(p);
            }

            if(mp.find(c) == mp.end()){
                mp[c] = new TreeNode(c);
            }

            if(isLeft){
                mp[p]->left = mp[c];
            }else{
                mp[p]->right = mp[c];
            }
            st.insert(c);
        }

        for(auto& node: mp){
            if(st.find(node.first) == st.end()){
                return node.second;
            }
        }
    return nullptr;
    }
};
