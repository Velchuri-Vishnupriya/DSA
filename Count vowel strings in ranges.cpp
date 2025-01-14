class Solution {
public:
bool isvowel(char ch){
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){return true;}
    return false;
}
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int q1=queries.size();
        vector<int> ans(q1);
        int n=words.size();
        vector<int> cursum(n);
        int sum=0;
        for(int i=0;i<n;i++){
            if(isvowel(words[i].back()) && isvowel(words[i][0])){
                sum++;
            }
            cursum[i]=sum;
        }
    for(int i=0;i<q1;i++){
        int l=queries[i][0];
        int r=queries[i][1];
        ans[i]=cursum[r]-((l>0) ? cursum[l-1] : 0);
    }
return ans;
    }
};
