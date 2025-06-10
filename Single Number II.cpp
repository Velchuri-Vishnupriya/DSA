//T.C : O(32*n)
//S.C: O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;

        for(int k=0; k<=31; k++){
            int temp = (1<<k); //leftshift operation on kth bit

            int countOnes = 0;

            for(int& num : nums){
                if((num & temp) == 0){}
                else countOnes ++;
            }
            
            if(countOnes % 3 == 1){
                result |= temp;
            }
        }
    return result;}
};
