class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(),trips.end(),[](const vector<int>&a,const vector<int>&b){
            return a[1]<b[1];
        });
        int currPass=0;//current passengers
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>minHeap;
        for(auto&trip:trips){
            int pass=trip[0],start=trip[1],end=trip[2];
            while(!minHeap.empty()&&minHeap.top().first<=start){
                currPass-=minHeap.top().second;
                minHeap.pop();
            }
            currPass+=pass;
            if(currPass>capacity){
                return false;
            }
            minHeap.push({end,pass});
        }
        return true;
    }
};