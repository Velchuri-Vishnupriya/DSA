//Brute Force
//T.C:O(N)
//S.c: O(1)

class Solution {
public:
const int M=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        int count=0;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int sum=0;
                for(int k=i;k<=j;k++){
                    sum+=arr[k];
                }
                if(sum%2 !=0 ){count++;}
            }
        }
        return count % M;
    }
};

//Better Approach
//T.C: O(n)
//S.C: O(1)

class Solution {
public:
const int M=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        int count=0;

        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
         sum+=arr[j];
         if(sum % 2 !=0){count++;}
            }
        }
        return count % M;
    }
};

//Approach-3 (Using Prefix sum array)
//T.C: O(n)
//S.C: O(n)
class Solution {
public:
const int M=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();

        vector<int> prefix(n,0);

        prefix[0]=arr[0];

        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+arr[i];
        }

        int cnt=0; int odd=0; int even=1;

        for(int i=0;i<n;i++){
            if(prefix[i]%2  !=0){
                //odd sum encounter even +ODD =odd;
                cnt=(cnt+even)%M;
                odd++;
            }
            else{
                cnt=(cnt+odd)%M;
                even++;
            }
        }

return cnt;

    }
};

//Approach-4 (using variable Sum)
//T.S :O(n)
//S.C: O(n)

class Solution {
public:
const int M=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
int sum=0;
int cnt=0;
int odd=0; int even=1;
for(int i=0;i<n;i++){
    sum+=arr[i];
    if(sum%2==0){
        //even sum encountered;
        //odd+EVEN=odd;
        cnt=(cnt+odd)%M;
        even++;
    }
    else{
        //Odd sum encountered;
        //even + ODD=even;
        cnt=(cnt+even)%M;
        odd++;
    }
}
  return cnt;  }
};
