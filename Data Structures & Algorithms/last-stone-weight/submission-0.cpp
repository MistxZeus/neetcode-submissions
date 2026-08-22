class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>max_heap;
        for(int stone:stones){
            max_heap.push(stone);
        }
        while(max_heap.size() > 1){
            int top1=max_heap.top();
            max_heap.pop();
            int top2=max_heap.top();
            max_heap.pop();
            int result=top1-top2;
            if(result>0)max_heap.push(result);
        }
        if(max_heap.size()==1)return max_heap.top();
        else return 0;
    }
};
