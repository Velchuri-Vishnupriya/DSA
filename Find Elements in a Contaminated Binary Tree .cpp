//Using DFS
//T.S & S.C=O(n) 
class FindElements {
public:
unordered_set<int> st;
void dfs(TreeNode* root,int x){
    if(!root) return;
    root->val=x;
    st.insert(x);
dfs(root->left,2*x+1);
dfs(root->right,2*x+2);
}
    FindElements(TreeNode* root) {
        dfs(root,0);
    }
    
    bool find(int target) {
  if(st.find(target)==st.end()) return false;
  
   return true;}
};

//using BFS
//T.S & S.C=O(n) 
class FindElements {
public:
unordered_set<int> s;
void bfs(TreeNode* root,int x){
    queue<TreeNode*> q;
    root->val=x;
    q.push(root);
    while(q.empty()==false){
        TreeNode* temp=q.front();
        q.pop();
        s.insert(temp->val);
        if(temp->left){
            temp->left->val=2*(temp->val)+1;
            q.push(temp->left);
        }
           if(temp->right){
            temp->right->val=2*(temp->val)+2;
            q.push(temp->right);
        }
    }
}
    FindElements(TreeNode* root) {
        bfs(root,0);
    }
    
    bool find(int target) {
  if(s.find(target)==s.end()) return false;
  
   return true;}
};
