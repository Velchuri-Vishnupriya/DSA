//Approach -1
//T.C: O(n*logn)
class Solution {
public:
    typedef pair<int, int> P;
    
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<P, vector<P>> pq;
        
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
        }

        vector<P> selected;
        while (k--) {
            selected.push_back(pq.top());
            pq.pop();
        }

        // lamda function
        sort(selected.begin(), selected.end(), [](P& a, P& b) {
            return a.second < b.second;
        });

        vector<int> ans;
        for (auto& p : selected) {
            ans.push_back(p.first);
        }

        return ans;
    }
};

//Approach -2 
//T.C: O(n)
class Solution {
public:
    typedef pair<int, int> P;
    
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> temp(begin(nums),end(nums));
        nth_element(begin(temp),begin(temp)+k-1,end(temp),greater<int>()); //Avg T.C:O(n)
        int kthLargest = temp[k-1];
        int countKthLargest = count(begin(temp),begin(temp)+k,kthLargest); //T.C:O(n)
        vector<int> ans;
        for(int& it : nums){//T.C: O(n)
            if(it > kthLargest){
                ans.push_back(it);
            }
            else if(it == kthLargest && countKthLargest){
                ans.push_back(it);
                countKthLargest--;
            }
            if(ans.size()==k) break;
        }
   return ans; }
};
