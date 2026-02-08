//T.C : O(n)
//S.C : O(h)

class Solution {
public: 
   bool balanced = true;
int R = 0;
int L = 0;
   int traverse(TreeNode* root){
    if(!root) return 0;

    int l = traverse(root -> left);
    int r = traverse(root -> right);

    if(abs(r - l) > 1){
        balanced = false;
    }

    if(r > l){
        R = 1;
        L =0;
    }else{
        R = 0;
        L = 1;
    }
    return max(l,r) + 1;
   }

    bool isBalanced(TreeNode* root) {
       traverse(root);
       if(R){
        cout<<"Right\n";
       }else{
        cout<<"Left\n";
       }
       return balanced;
    }
};
