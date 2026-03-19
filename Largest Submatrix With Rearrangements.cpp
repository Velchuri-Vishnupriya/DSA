//Approach - 1
//T.C : O(m*n*logn)
//S.C : O(m*n)
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
       int m = matrix.size();
       int n = matrix[0].size();

       int maxArea = 0;

       for(int row = 0; row < m; row++){//O(m)
        for(int col = 0; col < n; col++){//O(n)
            if(matrix[row][col] == 1 && row > 0){
                matrix[row][col] += matrix[row-1][col];//cum 1s
            }
        }

        vector<int> heights = matrix[row];
        sort(begin(heights), end(heights), greater<int>());//O(logn)

        for(int i = 0; i < n; i++){//O(n)
            int base = i + 1;
            int height = heights[i];

            maxArea = max(maxArea, base*height);
        }
       }
   return maxArea; }
};

//Approach - 2
//T.C : O(m*n*logn)
//S.C : O(n)
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
       int m = matrix.size();
       int n = matrix[0].size();

       int maxArea = 0;
       vector<int> prevRow(n,0);

       for(int row = 0; row < m; row++){//O(m)
       
       vector<int> currRow = matrix[row];

        for(int col = 0; col < n; col++){//O(n)
            
            if(currRow[col] == 1)currRow[col] += prevRow[col];//cum 1s
            }
        

        vector<int> heights = currRow;
        sort(begin(heights), end(heights), greater<int>());//O(logn)

        for(int i = 0; i < n; i++){//O(n)
            int base = i + 1;
            int height = heights[i];

            maxArea = max(maxArea, base*height);
        }

        prevRow = currRow;
       }
   return maxArea;}
};

//Approach - 3
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
       int m = matrix.size();
       int n = matrix[0].size();
       int maxArea = 0;

       vector<pair<int,int>> prevHeight;//{height, col}

       for(int row = 0; row < m; row++){

        vector<pair<int,int>> currHeight;
        vector<bool> seen(n,false);

        //forst we will fill those cols which had got height in prevHeights

        for(auto[height, col]: prevHeight){
            if(matrix[row][col] == 1){
                currHeight.push_back({height+1, col});
                seen[col] = true;
            }
        }

for(int col = 0; col < n; col++){
    if(!seen[col] && matrix[row][col] == 1){
        currHeight.push_back({1,col});
    }
}

for(int i = 0; i < currHeight.size(); i++){
    int height = currHeight[i].first;
    maxArea = max(maxArea, height*(i+1));
}
prevHeight = currHeight;
       }
return maxArea;
}
};
