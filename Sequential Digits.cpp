//T.C : O(1)
/*Time complexity explanation recursion loop is called 9 times and the patterns is something like this
9+8+7+...1 = 45 
so total 45 times the function is called*/
//S.C: O(1)
/*recursion depth goes at max to a val of 9*/
class Solution {
public:
void generate(int num, int lastDigit, int& low, int& high, vector<int>& ans){
    if(num > high || lastDigit > 9)return;

    if(num >= low)ans.push_back(num);

    generate(num*10+lastDigit+1, lastDigit+1, low, high, ans);
}
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int i=1; i<10; i++){
            generate(i,i,low,high,ans);
        }
        sort(begin(ans), end(ans));
        return ans;
    }
};
