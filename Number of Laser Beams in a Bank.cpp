//T.C : O(m*n) - m = no.of rows n = np.of cols 
//S.C : O(m) - no.of rows
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int count = 0;
        vector<int> vec;
        for(auto& s : bank){//O(m)
            for(char ch : s){//O(n)
                if(ch == '1'){
                    count++;
                }
            }
            if(count > 0) vec.push_back(count);
            count = 0;
        }
        //*
        count = 0;
        if(vec.size() < 2) return 0;
        for(int i = 0; i < vec.size()-1; i++){
count += (vec[i]*vec[i+1]);
        }
   return count; }
};
