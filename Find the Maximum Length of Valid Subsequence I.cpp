//T.C : O(n)
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int evens = 0;
        int odds = 0;
        for(auto& it : nums){
            if(it % 2 == 0) evens++;
            else odds++;
        }
        int even_odd_max = max(evens , odds);
        int parity = nums[0] % 2;
        int alt = 1;
        for(int i=1; i < nums.size(); i++)
        {
            int currparity = nums[i]%2;
if(currparity != parity) {
    alt++;
    parity = currparity;
       }
        }
        return max(even_odd_max , alt );
    }
};
