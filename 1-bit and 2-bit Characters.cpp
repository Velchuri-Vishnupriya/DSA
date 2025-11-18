//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
     int n = bits.size();
     int i = 0;
     while (i < n){
        if(bits[i] == 1){
            i+=2;
            if(i >= n) return false;
        }else{
            i++;
        }
     }
     return true;
    }
};

//Approach - 2:
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
int n = bits.size();
int count = 0;
for(int i = n-2; i >= 0; i--){
  if(bits[i]==1) count++;
  else break;
}
return count%2 == 0 ? true : false;
    }
};
