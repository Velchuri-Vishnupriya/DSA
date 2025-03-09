//Sliding Window
//O(N)-T.C
//O(1)-S.C

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
      int n = colors.size();

        int N = n + (k-1);
        for(int i = 0; i < k-1; i++) {
            colors.push_back(colors[i]); //to handle wrap around (circular array)
        }

        int result = 0;
        int i = 0;
        int j = 1; 
        while(j < N) {
            if(colors[j] == colors[j-1]) {
                i = j;
                j++;
                continue;
            }

            if(j - i + 1 == k) {
                result++;
                i++;
            }

            j++;
        }

        return result;
    }
};


//Another approach with O(N) time complexity
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
      int n = colors.size();

        int N = n + (k-1);
        for(int i=0;i<k-1;i++){colors.push_back(colors[i]);}
     int i=1;
     int last=colors[0];
     int len=1;
     int res=0;
     while(i<N){
        if(last==colors[i]){
            len=1;
           
        }
        else{
            len++;
            if(len>=k) res++;
    
        }
         last=colors[i];
        i++;
     }
     return res;
    }
};
