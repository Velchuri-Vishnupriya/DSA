//T.C : O(m + n*9)~O(m+n)
//S.C : O(m)
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> st;
        for(auto& obs : obstacles){//O(m)
            string key = to_string(obs[0]) + "_" + to_string(obs[1]);
            st.insert(key);
        }

        int x = 0;
        int y = 0;
        int maxD = 0;

        //initially pointing to North
        pair<int,int> dir = {0,1};

        for(int i=0; i<commands.size(); i++){//O(n)
            if(commands[i] == -2){//left
                dir = {-dir.second, dir.first};
            }else if(commands[i] == -1){//right
            dir = {dir.second, -dir.first};
            }else{
                for(int step=0; step<commands[i]; step++){//O(maxVal)~O(9)
                    int newX = x + dir.first;
                    int newY = y + dir.second;

                    string key = to_string(newX) + "_" + to_string(newY);
                    if(st.find(key) != st.end()){
                        break; 
                    }

                    x = newX;
                    y = newY;
                }
            }
            maxD = max(maxD, x*x + y*y);
        }
   return maxD;
    }
};
