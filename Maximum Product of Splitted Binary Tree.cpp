//T.C : O(n)
//S.C : O(1)
class Solution {
public:
long SUM = 0;
long maxP = 0;
const int M = 1e9 + 7;

int find(TreeNode* root){
    if(root == NULL) return 0;

    int leftSum = find(root->left);
    int rightSum = find(root->right);
    long subTreeSum = root->val + leftSum + rightSum;

    long S2 = SUM - subTreeSum;
    maxP = max(maxP, subTreeSum*S2);

return subTreeSum;
}
   int maxProduct(TreeNode* root) {
            if(root == NULL)return 0;
            maxP = 0;

            SUM = find(root);

            find(root);

            return maxP % M;
             }
};
