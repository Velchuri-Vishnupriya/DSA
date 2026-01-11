//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> right(n);
        vector<int> left(n);

        stack<int> st;
        for(int  i = 0; i < n; i++){
            if(st.empty()){
                left[i] = -1;
            }else{
                while(!st.empty() && heights[st.top()] >= heights[i]){
                    st.pop();
                }
                left[i] = (st.empty()) == true ? -1 : st.top();
            }
            st.push(i);
        }

        while (!st.empty()) {
    st.pop();
}

         for(int  i = n-1; i >= 0; i--){
            if(st.empty()){
                right[i] = n;
            }else{
                while(!st.empty() && heights[st.top()] >= heights[i]){
                    st.pop();
                }
                right[i] = (st.empty() == true) ? n : st.top();
            }
            st.push(i);
        }

        int maxArea = 0;
        for(int i = 0; i < n; i++){
            int width = right[i] - left[i] - 1;
            maxArea = max(maxArea, width*heights[i]);
        }
    return maxArea;
    }
};
