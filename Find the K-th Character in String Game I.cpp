//Approach -1 
class Solution {
public:
//T.C :2^0 + 2^1 + 2^2 +......2^n = O(2^n) = O(k) 
    char kthCharacter(int k) {
        string word = "a";
        while(word.size() < k) 
        {
            string next ="";
            for(auto& it:word){
                next += static_cast<char>(it + 1);
            }
            word += next;
        }
        return word[k-1];
    }
};

//Approach - 2
class Solution {
public:
//T.C : O(k)
    char kthCharacter(int k) {
       int cntbits = 0;
       int K = k - 1;
       while(K){
        cntbits += ((K&1));
        K>>=1;
       }
    return static_cast<char>('a'+cntbits);
    }
};
