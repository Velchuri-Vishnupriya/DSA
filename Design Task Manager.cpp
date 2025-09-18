//T.C : O(log(n)) in worst cases O(n*log(n))
//S.C : O(n) -> heap + maps
class TaskManager {
public:
typedef pair<int,int> P;
priority_queue<P> maxHeap; //priroity, task_id
unordered_map<int,int> taskPrioMap; //task->prio
unordered_map<int,int> taskOwnerMap; //task->userId
    TaskManager(vector<vector<int>>& tasks) {
        for(auto& it: tasks){
            int priority = it[2];
            int taskId = it[1];
            int userId = it[0];
            maxHeap.push({priority, taskId});
            taskPrioMap[taskId] = priority;
            taskOwnerMap[taskId] = userId;
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskPrioMap[taskId] = priority; //Avg = O(1)
        taskOwnerMap[taskId] = userId; //Avg  = O(1)
        maxHeap.push({priority, taskId}); //O(log(n))
    }
    
    void edit(int taskId, int priority) {
        maxHeap.push({priority,taskId});//O(log(n))
        taskPrioMap[taskId] = priority; //Avg = O(1)
    }
    
    void rmv(int taskId) {
        taskPrioMap[taskId] = -1;
    }
    
    int execTop() {
        while(!maxHeap.empty()){//O(n)
            auto& it = maxHeap.top();
            if(it.first == taskPrioMap[it.second]){
                taskPrioMap[it.second] = -1;
                return taskOwnerMap[it.second];
            }
              maxHeap.pop(); //log(n)
        }
        return -1;
    }
};
