class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        for(int i=0;i<tasks.size();i++){
            tasks[i].push_back(i);
        }
        sort(tasks.begin(),tasks.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>minHeap;
        int i=0;
        long long  time=0;
        vector<int>res;
        while(i<n||!minHeap.empty()){
            while(i<n&&tasks[i][0]<=time){
                minHeap.push({tasks[i][1],tasks[i][2]});
                i++;
            }
            if(minHeap.empty()){
                time=tasks[i][0];
            }
            else{
                pair task=minHeap.top();
                minHeap.pop();
                time+=task.first;
                res.push_back(task.second);
            }
        }
        return res;
    }
};