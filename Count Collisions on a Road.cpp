//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int countCollisions(string d) {
        int n = d.length();
        
        int i = 0; //left boundary
        int j = n-1; //right boundary

        while(i < n && d[i] == 'L'){
            i++;
        }

        while(j >= 0 && d[j] == 'R'){
            j--;
        }

        int collisons = 0;
        while(i <= j){
            if(d[i] != 'S'){
                collisons++;
            }
            i++;
        }
    return collisons;
    }
};
