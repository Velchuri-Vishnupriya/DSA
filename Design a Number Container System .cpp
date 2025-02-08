//Approach-1 using ordered set
//T.C : O(log(n))
//S.C : O(n)
class NumberContainers {
public:
unordered_map<int,int> idxToNum;
unordered_map<int,set<int>> numToIdx;
    NumberContainers() {}
    
    void change(int index, int number) {
        if(idxToNum.count(index)){//O(1)
            int prevnum=idxToNum[index];
            numToIdx[prevnum].erase(index);//O(log n)
            if(numToIdx[prevnum].empty()) numToIdx.erase(prevnum); //O(1)
        }
        idxToNum[index]=number;
        numToIdx[number].insert(index);//O(log n)
    }
    
    int find(int number) {
        if(numToIdx.count(number)){//O(1)
            return *numToIdx[number].begin(); //O(1)
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */

//Approach-2 using minheap
//T.C : O(log n)
//S.C: O(n)
class NumberContainers {
public:
unordered_map<int,int> idxToNum;
unordered_map<int,priority_queue<int,vector<int>,greater<int>>> numToIdx;
    NumberContainers() {}
    
    void change(int index, int number) {
       idxToNum[index]=number;//O(1)
       numToIdx[number].push(index);//O(log n)
    }
    
    int find(int number) {
        if(numToIdx.count(number)){
            auto& pq=numToIdx[number];
            while(!pq.empty()){
                int idx=pq.top();
                if(idxToNum[idx]==number) return idx;
                pq.pop();
            }
        }
     
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
