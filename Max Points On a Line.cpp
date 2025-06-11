//Brute Force : O(n^3) - ACCEPTED
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 1)
            return 1;
        
        int result = 0;
        
        for(int i = 0; i<n; i++) {
            
            for(int j = i+1; j<n; j++) {
                
                int count = 2;
                
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                
                for(int k = 0; k < n; k++) {
                    
                    if(k != i && k != j) {
                        int dx_ = points[k][0] - points[i][0];
                        int dy_ = points[k][1] - points[i][1];
                        
                        if(dx_ * dy == dy_ * dx)
                            count++;
                    }    
                }
                
                result = max(result, count);
            }
        }
        
        return result;
    }
};



//Approach -2 - using atan2
//T.C : O(n^2) 
//S.C : O(n)
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();

        if(n == 1) return 1;

        int result = 0;

        for(int i = 0; i < n; i++){
            //P1
unordered_map<double , int> mp;

        for(int j=0; j<n; j++){
           
           if(j == i) continue;

auto dy = points[j][1] - points[i][1];
auto dx = points[j][0] - points[i][0];

auto theta = atan2(dy , dx); //atan2 is built in function to find theta in c+=
mp[theta]++;
        }
        for(auto& it : mp){
                 result = max(result, it.second + 1);
        }
        }
    return result;}
};

//Approach - 3 - w/o using atan2
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();

        if(n == 1) return 1;

        int result = 0;

        for(int i = 0; i < n; i++){
            //P1
unordered_map<string , int> mp;

        for(int j=0; j<n; j++){
           
           if(j == i) continue;

auto dy = points[j][1] - points[i][1];
auto dx = points[j][0] - points[i][0];

auto gcd = __gcd(dy , dx); //atan2 is built in function to find theta in c+=
string key = to_string(dy/gcd) + "_" +to_string(dx/gcd);
mp[key]++;
        }
        for(auto& it : mp){
                 result = max(result, it.second + 1);
        }
        }
    return result;}
};
