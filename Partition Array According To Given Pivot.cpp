//Using 3 data structures to store < , = ,>
//T.S: O(n)
//S.C: O(n)

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        queue<int> q1, q2,q3; 
        vector<int> result;
        
        for (int num : nums) {
            if (num <pivot) q1.push(num);
            else if(num==pivot) q3.push(num);
            else q2.push(num);
        }

        while (!q1.empty()) {
            result.push_back(q1.front());
            q1.pop();
        }

          while (!q3.empty()) {
            result.push_back(q3.front());
            q3.pop();
        }

        while (!q2.empty()) {
            result.push_back(q2.front());
            q2.pop();
        }

        return result;
    }
};

//using 1 data structure
//T.S:O(N)
//S.C:O(1)

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
       
        vector<int> result;
        
        for (int num : nums) {
            if (num <pivot) result.push_back(num);
            
        }

             for (int num : nums) {
            if (num==pivot) result.push_back(num);
            
        }

              for (int num : nums) {
            if (num>pivot) result.push_back(num);
            
        }



       
        return result;
    }
};

//Another Approach
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
       int n=nums.size();
        vector<int> result(n,0);
        int countless=0;
        int countequal=0;
for(int num:nums){
if(num<pivot) countless++;
if(num==pivot) countequal++;
}

int i=0;
int j=countless;
int k=countless+countequal;

for(int num:nums){
    if(num < pivot) {result[i]=num; i++;}
    else if(num==pivot){result[j]=num;j++;}
    else{result[k]=num;k++;}
}
        return result;
    }
};

//+1 Approach
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
       int n=nums.size();
        vector<int> result(n);
     //ori array
     int i=0;
     int j=n-1;
     //res array;
     int i_=0;
     int j_=n-1;
     while(i<n && j>=0){
        if(nums[i]<pivot){
            result[i_]=nums[i];
            i_++;
        }
        if(nums[j]>pivot){
            result[j_]=nums[j];
            j_ --;
        }
     i++;
     j--;
     }

     while(i_ <= j_){
        result[i_]=pivot;
        i_++;
     }
        return result;
    }
};
