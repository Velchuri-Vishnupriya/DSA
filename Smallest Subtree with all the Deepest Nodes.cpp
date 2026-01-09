//Using Post order traversl
//T.C : O(N)
//S.C : O(1)
class Solution {
public:
    typedef pair<int,TreeNode*> P;
    P solve(TreeNode* root){
        if(!root) return{0,NULL};

        //left child
        auto L = solve(root->left);
        auto R = solve(root->right);

        if(L.first > R.first) return {L.first+1, L.second};
        else if(R.first > L.first) return {R.first+1, R.second};
        return {L.first+1, root};
} 

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
     return solve(root).second;   
    }
};
