//BFS
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
    int maxLevelSum(TreeNode* root) {
        int maxSum = INT_MIN;
        int level = 0;

        queue<TreeNode*> que;
        que.push(root);

        int currLevel = 1;

        while(!que.empty()){
            int n = que.size();

            int sum = 0;
//Traversing all elements of curr level
            while(n--){
                TreeNode* temp = que.front();
                que.pop();

                sum += temp -> val;
                if(temp->left) que.push(temp->left);
                if(temp->right) que.push(temp->right);
            }
            if(sum > maxSum){
                level = currLevel;
                maxSum = sum;
            }
             currLevel++;
        }
   return level;
   }
};

//DFS
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
map<int,int> mp;

void DFS(TreeNode* root, int level){

    if(!root) return;

    mp[level] += root -> val;

    DFS(root->left, level+1);
    DFS(root->right, level+1);
}
    int maxLevelSum(TreeNode* root) {
        mp.clear();

        DFS(root,1);

        int maxSum = INT_MIN;
        int resultLevel = 0;

        for(auto& it : mp){
            int lvl = it.first;
            int sum = it.second;

            if(sum > maxSum){
                maxSum = sum;
                resultLevel = lvl;
            }
        }
   return resultLevel;
   }
};
