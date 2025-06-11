//Brute Force
//T.C : O(n^3)
//S.C : O(1)
class Solution {
public:
typedef pair<int,int> P;
int findEquationValue(P& p1,P& p2,P& p3){
    int x1 = p1.first;
    int y1 =  p1.second;

        int x2 = p2.first;
    int y2 =  p2.second;

    int x3 = p3.first;
    int y3 =  p3.second;

    return (y3 - y2) * (x2 - x1) - (y2 - y1)*(x3 - x2);
}
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        sort(begin(trees), end(trees));

        vector<vector<int>> result;

        deque<pair<int, int>> upper, lower;

        for(auto point : trees){
            
            int l = lower.size();
            int u = upper.size();

while(l >= 2 && findEquationValue(lower[l-2] , lower[l-1], {point[0], point[1[1]}) < 0 ){
    l--;
    lower.pop_back(); 
}

while(l >= 2 && findEquationValue(upper[l-2] , upper[l-1], {point[0], point[1[1]}) > 0 ){
    u--;
    upper.pop_back(); 
}

upper.push_back({point[0],point[1]});
lower.push_back({point[0],point[1]});
        }

set<P> st;

for(auto& point : lower){
    st.insert(point);
}

for(auto& point : upper){
    st.upper(point);
}
   
   for(auto& point : st){
    result.push_back({point.first,point.second});
} 
return result;}
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
