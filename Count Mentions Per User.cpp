//T.C : O(n*log n)
//S.C : O(n)
class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
   vector<int>mention(numberOfUsers,0);
   unordered_map<int,int> mp;

   //sort by time stamp and if equal time stamp then OFFLINE first
   //O(n*log n)
   sort(events.begin(), events.end(), [&](auto& a, auto& b){
    int t1 = stoi(a[1]);
    int t2 = stoi(b[1]);
    if(t1 != t2) return t1 < t2;
    return a[0] == "OFFLINE";
   });
   
   for(auto& it : events){
    if(it[0] == "MESSAGE"){
        int time = stoi(it[1]);

        if(it[2]=="ALL"){
            for(int i=0; i<numberOfUsers; i++){
                mention[i]++;
            }
        }
        else if(it[2] == "HERE"){
            for(int i=0; i<numberOfUsers; i++){
                if(mp.count(i)){
                    if(time >= mp[i]){
                        mention[i]++;
                    }
                }else{
                    mention[i]++;
                }
            }
        }
        else{
            string temp = "";
            string s = it[2];
            for(char ch : s){
                if(isdigit(ch)){
                    temp.push_back(ch);
                }else{
                    if(!temp.empty()){
                        int user = stoi(temp);
                        mention[user]++;
                    }
                    temp="";
                }
            }
            if(!temp.empty()){
                int user = stoi(temp);
                mention[user]++;
            }
        }
    }
    else{
        int user = stoi(it[2]);
        int time = stoi(it[1]);
        mp[user]=time+60;
    }
   }
   return mention; }
};
