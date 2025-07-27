//Approach - 1;
//T.C : O(n)
class Solution {
public:
    typedef pair< int , int > P;
    int countHillValley(vector<int>& nums) {
       int n = nums.size();

       set<P> hill ;
       set<P> valley;

       int j , k ;

       for(int i=1 ; i < n-1 ; i++ ){
j = i - 1;
while(j >= 0 && nums[i] == nums[j]){
    j--;
}

if(j < 0) continue;

k = i + 1;
while(k < n && nums[i] == nums[k]){
    k++;
}

if(k >= n) continue;

if(nums[i] > nums[j] && nums[i] > nums[k]) hill.insert({j,k});

if(nums[i] < nums[j] && nums[i] < nums[k]) valley.insert({j,k});
 }
    
   return hill.size() + valley.size();}
};

//Approach - 2

//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        vector<int> V;

        // Remove only consecutive duplicates
        V.push_back(nums[0]);
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1])
                V.push_back(nums[i]);
        }

        int count = 0;
        for (int i = 1; i < V.size() - 1; i++) {
            if (V[i] > V[i - 1] && V[i] > V[i + 1]) count++; // hill
            if (V[i] < V[i - 1] && V[i] < V[i + 1]) count++; // valley
        }

        return count;
    }
};
