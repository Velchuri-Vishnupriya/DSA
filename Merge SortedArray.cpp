//T.C:O(n*log n)
//Classic Merge Sort example
class Solution {
public:
void Merge(vector<int>&nums1,int l,int m,int r){
    int n1= m-l+1;
    int n2= r-m;

    vector<int> L(n1);
    vector<int> R(n2);

for(int i = 0; i < n1; i++) {
    L[i] = nums1[l + i];  
}
for(int j = 0; j < n2; j++) {
    R[j] = nums1[m + 1 + j];  
}


    int i=0;
    int j=0;
    int k = l;
    while(i<n1 && j<n2){
        if(L[i] < R[j]){
            nums1[k] = L[i];
              i++;
        }
        else{
            nums1[k] = R[j];
          j++;
          }
        k++;
    }

    while(i<n1){
        nums1[k]=L[i];
          i++;
          k++;
    }
    while(j<n2){
        nums1[k]=R[j];
          j++;
          k++;
    }
}
void merge_sort(vector<int>& nums1, int l, int r) {
    if (l >= r) return;

    int mid = l + (r - l) / 2;  

    merge_sort(nums1, l, mid);
    merge_sort(nums1, mid + 1, r);

    Merge(nums1, l, mid, r);
}

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0;i<n;i++){
            nums1[m+i]=nums2[i];
        }
        int r = m+n-1;
        merge_sort(nums1,0,r);
        return;
    }
};
