//Brute Force
//This is a BFS traversal and in BFS traversal T.C is V + E here V = n and Edges is number of start zeros*(maxF - minF)
//T.C : O(n*k) at max k can be n hence ~n*n
class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.length();

        int startZeros = 0;
        for(char& ch: s){
            if(ch == '0') startZeros++;
        }

        if(!startZeros) return 0; //aldready everything is 1111...

        vector<int> operations(n+1, -1);
        //operations[z] = min op required to reach state in which we have z zeros

        queue<int> que;
        que.push(startZeros);
        operations[startZeros] = 0;

        while(!que.empty()){
            int z = que.front();
            que.pop();

            int minF = max(0, k - n + z);
            int maxF = min(k, z);

            for(int f = minF; f <= maxF; f++){
                int newZ = z + k - 2*f;

                if(operations[newZ] == -1){
                    operations[newZ] = operations[z] + 1;

                    if(newZ == 0) return operations[newZ];

                    que.push(newZ);
                }
            }
        }
return -1;
    }
};

//Optimal
//In this approach at max we visit n states and each time we apply logn so n*logn is T.C
class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.length();

        int startZeros = 0;
        for(char& ch: s){
            if(ch == '0') startZeros++;
        }

        if(!startZeros) return 0; //aldready everything is 1111...

        vector<int> operations(n+1, -1);
        //operations[z] = min op required to reach state in which we have z zeros

        set<int> evenSet;
        set<int> oddSet;

        for(int count = 0; count <= n; count++){
            if(count % 2){
                oddSet.insert(count);
            }else{
                evenSet.insert(count);
            }
        }

        queue<int> que;
        que.push(startZeros);
        operations[startZeros] = 0;
        if(startZeros % 2)oddSet.erase(startZeros);
        else{
            evenSet.erase(startZeros);
        }

        while(!que.empty()){
            int z = que.front();
            que.pop();

            int minF = max(0, k - n + z);
            int maxF = min(k, z);

            int min_new_z = z + k -2*maxF;
            int max_new_z = z + k -2*minF;

            set<int> &currSet = (min_new_z % 2 == 0) ? evenSet : oddSet;

            auto it = currSet.lower_bound(min_new_z);

            while(it != currSet.end() && *it <= max_new_z){
                int newZ = *it;

                if(operations[newZ] == -1){
                    operations[newZ] = operations[z] + 1;

                    if(newZ == 0) return operations[newZ];

                    que.push(newZ);
                }
                it = currSet.erase(it);
            }
        }
return -1;
    }
};
