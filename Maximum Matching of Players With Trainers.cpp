//Approach - 1;
//T.C : O(m*n) m = players.size(), n = trainers.size()  
//S.C: O(n)
class Solution {
public:
    int matchPlayersAndTrainers(std::vector<int>& players, std::vector<int>& trainers) {
   int m = players.size();
   int n = trainers.size();

   int res = 0;
   sort(begin(players), end(players));
   sort(begin(trainers), end(trainers));
int prev = -1;
   vector<int> V(begin(trainers), end(trainers));
   for(int i=0; i<m; i++){//O(m)
bool found = false;
for(int j = prev+1; j < n; j++ ){//O(n)
    if(V[j] >= players[i]){
        found = true;
        prev = j;
        break;
    }
}
if(found == true){res++;}
else return res;
   }
   return res; }
};

//Approach -2
//T.C : O(m+n) m = players.size(), n = trainers.size()  
//S.C: O(n)
class Solution {
public:
    int matchPlayersAndTrainers(std::vector<int>& players, std::vector<int>& trainers) {
   int m = players.size();
   int n = trainers.size();

   int res = 0;

   sort(begin(players), end(players));
   sort(begin(trainers), end(trainers));

   vector<int> V(begin(trainers), end(trainers));

   int i = 0; int j = 0;
   while(i < m && j < n){
    while(j < n){
        if(V[j] >= players[i]){
            res++;
            j++;
            break;
        }
        j++;
    }
    i++;
   }
    return res;}
};
