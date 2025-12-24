//T.C : O(m*log m) m= capacity size
class Solution {
public:
    int minimumBoxes(vector<int>& apples, vector<int>& capacity) {
        int totalApples = accumulate(apples.begin(), apples.end(), 0);//O(n)

        sort(begin(capacity), end(capacity), [](int& a, int& b)
        {return a > b;}
        );//(m*log m)

        int mBoxes = 0;
        for(int i = 0; i < capacity.size(); i++){//O(m)
            mBoxes += capacity[i];
            if(mBoxes >= totalApples) return i + 1;
        }
    return capacity.size();
    }
};
