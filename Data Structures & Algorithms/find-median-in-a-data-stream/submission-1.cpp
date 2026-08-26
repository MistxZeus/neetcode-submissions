class MedianFinder {
    priority_queue<int>maxHeap;
    priority_queue<int,vector<int>,greater<int>>minHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.empty() || num <= maxHeap.top()){
            maxHeap.push(num);
        }else{
            minHeap.push(num);
        }
        
        if((int)maxHeap.size() - (int)minHeap.size() > 1){
            int val=maxHeap.top();
            maxHeap.pop();
            minHeap.push(val);
        }else if((int)minHeap.size() - (int)maxHeap.size() > 1){
            int val=minHeap.top();
            minHeap.pop();
            maxHeap.push(val);
        }
    }
    
    double findMedian() {
        if(minHeap.size()==maxHeap.size()){
            return (minHeap.top()+maxHeap.top())/2.0;
        }else{
            return maxHeap.size() > minHeap.size() ? maxHeap.top() : minHeap.top();
        }
    }
};
