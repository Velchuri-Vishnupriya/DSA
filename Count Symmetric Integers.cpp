//Brute Force
//T.C:O((high-low+1))*d -->d=digits 
//S.C:O(d);
class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;

        for (int i = low; i <= high; i++) {
            string x = to_string(i);
            int len = x.length();

            if (len % 2 != 0) continue; // skip if not even number of digits

            int n = len / 2;
            int leftSum = 0, rightSum = 0;

            for (int j = 0; j < n; j++) {
                leftSum += x[j] - '0';        
                rightSum += x[j + n] - '0';  
            }

            if (leftSum == rightSum) count++;
        }

        return count;
      
    }
};

//Optimal Approach (using / nd %)
//T.C:O(high-low+1)
//S.C:O(1)
class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for(int i=low;i<=high;i++){
            if(10<i && i<100 && i%11==0){count++;}
            else if(1000<i && i<10000){
                int first=i/1000;
                int second=(i/100)%10;
                int third=(i/10)%10;
                int fourth=(i%10);
                if(first+second==third+fourth) count++;
            }
    
        }
        return count;
    }
};
