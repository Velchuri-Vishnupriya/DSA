//T.S : O(n)
//S.C :O(n) - Recurrsion stack space

class Solution {
public:
TreeNode* solve(int pres,int posts,int preend,vector<int>& preorder,vector<int>&postorder,unordered_map<int,int>& mp){
    if(pres>preend) return NULL;

    TreeNode* root=new TreeNode(preorder[pres]);

    if(pres==preend) return root;

    int next=preorder[pres+1];

    int j=mp[next];

    int num=j-posts+1;

    root->left=solve(pres+1,posts,pres+num,preorder,postorder,mp);
    
    root->right=solve(pres+num+1,j+1,preend,preorder,postorder,mp);

    return root;

}
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
    int n=preorder.size();
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[postorder[i]]=i;
    }
    return solve(0,0,n-1,preorder,postorder,mp);
    }
};
