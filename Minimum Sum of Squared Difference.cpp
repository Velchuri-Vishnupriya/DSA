//T.C : O(n+M) (M=1e5)
//S.C :O(M) (M=1e5)
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<int> countDiff(1e5+1, 0);
        for(int i=0; i<n; i++){
            int d = abs(nums1[i]-nums2[i]);
            countDiff[d]++;
        }

        int K = k1 + k2;

        for(int currDiff = 1e5; currDiff >= 0; currDiff--){
            int count = countDiff[currDiff];
            int countOps = min(count, K);
            if(currDiff-1 < 0)continue;
            countDiff[currDiff] -= countOps;
            countDiff[currDiff-1] += countOps;
            K -= countOps;
            if(K <= 0)break;
        }

        long long result=0;

        for(int currDiff=1; currDiff<=1e5; currDiff++){
            int freq = countDiff[currDiff];
            long long toAdd = 1LL*freq*currDiff*currDiff;
            result += toAdd;
        }
return result;
    }
};
