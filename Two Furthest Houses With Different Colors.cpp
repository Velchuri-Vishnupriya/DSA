//2 - Pass
//T.C : O(2*n)~O(n)
//S.C : O(1)
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int i = 0;
        int j = n - 1;

        int res = 0;

        while(i < j){
            if(colors[i] != colors[j]){
                res = max(res, abs(j-i));
                break;
            }else{
                j--;
            }
        }

i = 0; j = n-1;

        while(i < j){
            if(colors[i] != colors[j]){
                res = max(res, abs(j-i));
                break;
            }else{
                i++;
            }
        }
    return res;
    }
};


//1 - Pass
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int i = 0;
        int j = n - 1;

        int res = 0;

        while(i < n){
            if(colors[i] != colors[0]){
                res = max(res ,i);
            }
            if(colors[i] != colors[j]){
                res = max(res, abs(j-i));
            }
            i++;
        }
    return res;
    }
};
