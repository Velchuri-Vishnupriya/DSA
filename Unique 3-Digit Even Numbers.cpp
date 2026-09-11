//T.C :O(N)
//S.C : O(1)
class Solution {
public:
    int totalNumbers(std::vector<int>& digits) {
/*freq arr from 0-9 */
vector<int> freq(10);
int n = digits.size();
for(int i=0; i<n; i++){//O(N)
    freq[digits[i]]++;
}
int total = 0;
for(int i=1; i<10; i++){//O(9)
    for(int j=0; j<10; j++){//O(10)
        for(int k=0; k<10; k+=2){//O(5)
            total += freq[i] > 0 &&
                           freq[j] > (i == j) &&
                           freq[k] > (i == k) + (j == k);
        }
    }
}
    return total;}
};
