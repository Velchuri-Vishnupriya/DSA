//we use nth_element an STL func to cal jsut the middle eleimante in the sorted order
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {vector<int> V;
    for(vector<int>& num: grid){
        for(int& nums: num){
            V.push_back(nums);
        }
    }
    int v=V.size();
        nth_element(begin(V),begin(V)+v/2,end(V));
  int target=V[v/2];
  int result=0;
  for(int i=0;i<v;i++){
    if(target%x != V[i]%x){return -1;}
      result+=(abs(V[i]-target)/x);
  }
return result;
    }
};
