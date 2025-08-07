//T.C :O(log(max_product) * m *logn) max_product = r - l
class Solution{
public:
    long long findCountSmallest(vector<int>& nums1, vector<int>& nums2, long long midProduct){ //O(m * log n)
        long long productsCount = 0;

        int n = nums2.size();
        int m = nums1.size();

        for(int i = 0; i < m; i++){
            if(nums1[i] >= 0){
               int l = 0;
               int r = n - 1;
               int m = -1;

               while(l <= r){
                int mid = l + (r - l)/2;
                long long prod = 1LL*nums1[i]*nums2[mid];

                if(prod <= midProduct){
                    m = mid;
                    l = mid + 1;
                }else{
                    r = mid -1;
                }
               }
               productsCount += (m + 1);
            }else{
                //prdt will be -ve nd right hand side will contain smaller prdts and left hand side largers
            int l = 0;
            int r = n - 1;
            int m = n; //invalid idx on the right hand side

            while(l <= r){
                int mid = l + (r - l)/2;
                long long prod = 1LL*nums1[i]*nums2[mid];

                if(prod <= midProduct){
                    m = mid;
                    r = mid - 1;
                }else{
                    l = mid + 1;
                }
            } 
            productsCount += (n - m ); 
            }
        }
        return productsCount;
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {//O(log(max_product) * m *logn) max_product = r - l
    long long result  = 0;

    long long l = -1e10;
    long long r = 1e10;

    while(l <= r){
        long long midProduct = l + (r - l)/2;

        long long countSmallest = findCountSmallest(nums1, nums2, midProduct);

        if(countSmallest >= k){
            result = midProduct ;
            r = midProduct - 1;
        }
        else{
            l = midProduct + 1;
        }
    }
    return result;
    }
};
