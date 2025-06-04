//USING DFS
//T.C: O(n) all the boxes are visited only incr
//S.C: O(n)
class Solution {
public:
int dfs(int box,vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, unordered_set<int>& visited, unordered_set<int>&  foundboxes){
    if(visited.count(box)) return 0;

    if(status[box] == 0){foundboxes.insert(box);
    return 0;}

visited.insert(box);
int candiescollected = candies[box];

for(int& insidebox: containedBoxes[box]){
    candiescollected += dfs(insidebox, status, candies, keys, containedBoxes, visited, foundboxes);
}

for(int& boxkey: keys[box]){
    status[boxkey]=1; //can be opened
    if(foundboxes.count(boxkey)){
        candiescollected += dfs(boxkey, status, candies, keys, containedBoxes, visited, foundboxes);
    }
    }

    return candiescollected;
}
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int candiescollected = 0 ;
unordered_set<int> visited;
unordered_set<int> foundboxes;
        for(int &box : initialBoxes){
            candiescollected += dfs(box, status, candies, keys, containedBoxes, visited, foundboxes);
}

return candiescollected;
    }
};

//USING BFS
//T.C: O(n) all the boxes are visited only incr
//S.C: O(n)
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int candiescollected = 0 ;
unordered_set<int> visited;
unordered_set<int> foundboxes;

queue<int> que; //insert boxes which are currently available and openable
for(int& box: initialBoxes){
    foundboxes.insert(box);
    if(status[box] == 1){
        que.push(box);
        visited.insert(box);
        candiescollected += candies[box];
    }
}

while(!que.empty())
{
    int box = que.front();
    que.pop();

    for(int& insidebox: containedBoxes[box]){
        foundboxes.insert(insidebox);
        if(status[insidebox] == 1 && visited.count(insidebox)==0){que.push(insidebox);
        visited.insert(insidebox);
        candiescollected += candies[insidebox];}
    }

    for(int &boxkey: keys[box]){
        status[boxkey] = 1;
        if(foundboxes.count(boxkey) && !visited.count(boxkey)){
            que.push(boxkey);
        visited.insert(boxkey);
        candiescollected += candies[boxkey];
        }
    }
}
return candiescollected;
    }
};
