//Approach 1
//T.C : O(m*n*min(m,n)*min(m,n)
//S.C : O(1) becuase set will have atmost 3 elements 
class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
       int m = grid.size();
       int n = grid[0].size();

       set<int> st;

       auto addSet = [&](int sum){
        st.insert(sum);
        if(st.size() > 3){
            st.erase(begin(st));
        }
       };

       for(int r = 0; r < m; r++){//O(m)
        for(int c = 0; c < n; c++){//O(n)

            //take each cell as centre and create rhomus 
            addSet(grid[r][c]);

            for(int side = 1; r-side >= 0 && r+side < m && c-side >= 0 && c+side < n; side++){//O(min(m,n))
                int sum = 0;
                for(int k = 0; k < side; k++){//O(min(m,n))
                    sum += grid[r-side+k][c+k];
                    sum += grid[r+k][c+side-k];
                    sum += grid[r+side-k][c-k];
                    sum += grid[r-k][c-side+k];
                }
                addSet(sum);
            }
        }
       }
    return vector<int>(rbegin(st), rend(st));
    }
};

//Approach 2 (modified version of brute force)
//T.C : O(m*n*min(m,n))
//S.C : O(m*n) becuase set will have atmost 3 elements 
class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
       int m = grid.size();
       int n = grid[0].size();

       set<int> st;

       //cumSum towards right diagonal
       vector<vector<int>> d1(m, vector<int>(n,0));

       //cumSum towards left diagonal
       vector<vector<int>> d2(m, vector<int>(n,0));

       for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            d1[i][j] = grid[i][j];
            if(i-1 >= 0 && j-1 >= 0){
                d1[i][j] += d1[i-1][j-1];
            }
            d2[i][j] = grid[i][j];
            if(i-1 >= 0 && j+1 < n){
                d2[i][j] += d2[i-1][j+1];
            }
        }
       }

       auto addSet = [&](int sum){
        st.insert(sum);
        if(st.size() > 3){
            st.erase(begin(st));
        }
       };

       for(int r = 0; r < m; r++){//O(m)
        for(int c = 0; c < n; c++){//O(n)

            //take each cell as centre and create rhomus 
            addSet(grid[r][c]);

            for(int side = 1; r-side >= 0 && r+side < m && c-side >= 0 && c+side < n; side++){//O(min(m,n))
                int sum = 0;
                
                int top_r = r-side, top_c = c;
                int right_r = r, right_c = c+side;
                int bottom_r = r+side, bottom_c = c;
                int left_r = r, left_c = c-side;

                //top vertex to right vertex
                sum += d1[right_r][right_c];
                if(top_r-1 >= 0 && top_c-1 >= 0){
                    sum -= d1[top_r-1][top_c-1];
                }

                //bottom vertex to right vertex
                sum += d2[bottom_r][bottom_c];
                if(right_r-1 >= 0 && right_c+1 < n){
                    sum -= d2[right_r-1][right_c+1];
                }

                //bottom to left
                sum += d1[bottom_r][bottom_c];
                if(left_r-1 >= 0 && left_c-1 >= 0){
                    sum -= d1[left_r-1][left_c-1];
                }

                //left to top
                sum += d2[left_r][left_c];
                if(top_r-1 >= 0 && top_c+1 < n){
                    sum -= d2[top_r-1][top_c+1];
                }

                //removethe doublr counted vertices
                sum -= grid[top_r][top_c];
                sum -= grid[right_r][right_c];
                sum -= grid[bottom_r][bottom_c];
                sum -= grid[left_r][left_c];

                addSet(sum);
            }
        }
       }
    return vector<int>(rbegin(st), rend(st));
    }
};
