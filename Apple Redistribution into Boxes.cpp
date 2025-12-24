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

//Using Count Sort
//T.C : O(n + maxEl + m) maxEl= capacity array max el
class Solution {
public:
    int minimumBoxes(vector<int>& apples, vector<int>& capacity) {
        int totalApples = accumulate(apples.begin(), apples.end(), 0);//O(n)

        //count sort
        int maxEl = *max_element(begin(capacity), end(capacity));
        vector<int> newCapacity(maxEl+1,0);
        for(int i = 0; i < capacity.size(); i++){//O(m)
            newCapacity[capacity[i]]++;
        }

        int mBoxes = 0;
        int count = 0;
       for(int i = maxEl; i >= 1; i--){//O(maxEl + m)
        while(newCapacity[i] > 0){//this loop visits every element of capcity exactly once
            mBoxes += i;
            count++;
            newCapacity[i]--;

            if(mBoxes >= totalApples) return count;
        }
       }

    return count;
    }
};
