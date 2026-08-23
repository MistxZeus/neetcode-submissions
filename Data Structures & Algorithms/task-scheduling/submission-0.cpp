class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);
        for(char c:tasks){
             freq[c-'A']++;
        }
        priority_queue<int>maxHeap;
        for(int i=0;i<26;i++){
            if(freq[i]>0)maxHeap.push(freq[i]);
        }
        int time=0;
        queue<pair<int,int>>q;
        while(q.size()>0||maxHeap.size()>0){
            time+=1;
            
            if(maxHeap.size()>0){
                int task=maxHeap.top()-1;
                maxHeap.pop();
                if(task>0)q.push({task,time+n});
            }
            
            if(q.size()>0&&q.front().second==time){
                maxHeap.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
