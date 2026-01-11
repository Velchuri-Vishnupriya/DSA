//T.C : O(m*n)
//S.C : O(n)
class Solution {
public:
    vector<int> getNSR(vector<int>& height){
        stack<int> st;
        int n = height.size();
        vector<int> right(n);

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && height[st.top()] >= height[i]){
                st.pop();
            }
            if(st.empty()) right[i] = n;
            else right[i] = st.top();

            st.push(i);
        }
        return right;
    }

    vector<int> getNSL(vector<int>& height){
        stack<int> st;
        int n = height.size();
        vector<int> left(n);

        for(int i = 0; i < n; i++){
            while(!st.empty() && height[st.top()] >= height[i]){
                st.pop();
            }
            if(st.empty()) left[i] = -1;
            else left[i] = st.top();

            st.push(i);
        }
        return left;
    }

    int findMaxArea(vector<int>& height){
        vector<int> right = getNSR(height);//O(n)
        vector<int> left = getNSL(height);//O(n)

        int maxArea = 0;
        for(int i = 0; i < height.size(); i++){//O(n)
            int width = right[i] - left[i] - 1;
            maxArea = max(maxArea, width * height[i]);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> height(n);

        for(int i = 0; i < n; i++){
            height[i] = matrix[0][i] - '0';
        }

        int maxArea = findMaxArea(height);
        //O(m*n)
        for(int row = 1; row < m; row++){//O(m)
            for(int col = 0; col < n; col++){//O(n)
                if(matrix[row][col] == '0') height[col] = 0;
                else height[col] += 1;
            }
            maxArea = max(maxArea, findMaxArea(height));//O(n)
        }

        return maxArea;
    }
};
