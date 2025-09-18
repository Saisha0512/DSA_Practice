struct cmp {
    bool operator()(const vector<int>& a, const vector<int>& b) {
        if (a[2] == b[2]) 
            return a[1] < b[1]; // Higher taskId first if priority same
        return a[2] < b[2]; // Higher priority first
    }
};

class TaskManager {
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    unordered_map<int, pair<int,int>> taskMap; // taskId -> {userId, priority}
public:
    TaskManager(vector<vector<int>>& tasks) {
        for(auto &task : tasks){
            pq.push(task);
            taskMap[task[1]] = {task[0], task[2]};
        }
    }
    
    void add(int userId, int taskId, int priority) {
        pq.push({userId, taskId, priority});
        taskMap[taskId] = {userId, priority};
    }
    
    void edit(int taskId, int newPriority) {
        auto it = taskMap.find(taskId);
        if (it != taskMap.end()){
            int userId = it -> second.first;
            taskMap[taskId] = {userId, newPriority};
            pq.push({userId, taskId, newPriority});
        }
    }

    void rmv(int taskId) {
        taskMap.erase(taskId);
    }
    
    int execTop() {
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int userId = curr[0], taskId = curr[1], priority = curr[2];

            auto it = taskMap.find(taskId);
            if (it != taskMap.end() && it -> second.first == userId && it -> second.second == priority){
                taskMap.erase(taskId);
                return userId;
            }
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */