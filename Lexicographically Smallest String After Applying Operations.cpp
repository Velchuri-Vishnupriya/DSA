//T.C : O(n^2)
//S.C : O(n * 10*n) n rotations possible at max and each rotation we can perform add operation 10 new digits so 10 new numbers 10*n , total n*10*n new strings
class Solution {
public:
string rotate(string curr, int b){
    return curr.substr(curr.length()-b) + curr.substr(0, curr.length()-b);
}
    string findLexSmallestString(string s, int a, int b) {
       string smallestString = s;

       unordered_set<string> visited;
       queue<string> que;
       que.push(s);
       visited.insert(s);

       while(!que.empty()){
        string curr = que.front();
        que.pop();

        if(curr < smallestString){
            smallestString = curr;
        }

        //Add a
        string temp = curr;
        for(int i = 1; i < temp.length(); i+=2){
            temp[i] = ((temp[i] - '0' + a) % 10) + '0';
        }

        if(!visited.count(temp)){
            visited.insert(temp);
            que.push(temp);
        }

        //Rotate by b positions right
        temp = rotate(curr, b);
         if(!visited.count(temp)){
            visited.insert(temp);
            que.push(temp);
        }
       }
   return smallestString; }
};
