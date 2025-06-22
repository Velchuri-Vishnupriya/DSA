//T.C:O(n*log n) --> n->n/2->4...1 log n times merge sort is called and merge function takes O(n) time so together n*log n
//S.C: O(n)
class Solution {
public:
void merge(vector<int>& nums,int l,int m,int r){
    int n1 = m-l+1;
    int n2 = r - m;

vector<int> L(n1);
vector<int> R(n2);

int k = l;

for(int i=0;i<n1;i++){
L[i] = nums[k];
k++;
}

for(int i=0;i<n2;i++){
R[i] = nums[k];
k++;
}
int i=0;
int j=0;
k=l;

while(i<n1 && j<n2){
    if(L[i] < R[j]){
        nums[k]=L[i];
    i++;
    }
    else{
        nums[k]=R[j];
        j++;
    }
    k++;
}
while(i<n1){
    nums[k]=L[i];
    i++; k++;
}
while(j<n2){
    nums[k]=R[j];
    j++; k++;
}

}
void merge_sort(vector<int>& nums,int l,int r){
    if(l>=r) return;
    int mid = l+(r-l)/2;

    merge_sort(nums,l,mid); 
    merge_sort(nums,mid+1,r);

    merge(nums,l,mid,r);
}
    vector<int> sortArray(vector<int>& nums) {
        int r = nums.size()-1;
        merge_sort(nums,0,r);
        return nums;
    }
};
