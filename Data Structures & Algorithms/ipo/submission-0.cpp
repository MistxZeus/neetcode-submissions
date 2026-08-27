class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>minHeap;
        for(int i=0;i<profits.size();i++){
            minHeap.push({capital[i],profits[i]});
        }
        priority_queue<int>maxHeap;
        int count=0;
        while(count<k){
            while(!minHeap.empty()&&minHeap.top().first<=w){
                auto[cap,p]=minHeap.top();
                maxHeap.push(p);
                minHeap.pop();
            }
            if(maxHeap.empty()){
                break;
            }else{
                w+=maxHeap.top();
                maxHeap.pop();
                count++;
            }
        }
        return w;
    }
};