class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>>stk;
        int maxArea=0;
        int lastIndex=0;
        for(int i=0;i<heights.size();i++){
            if(!stk.empty()&&heights[i]<stk.top().first){
            while(!stk.empty()&&heights[i]<stk.top().first){
                auto pair=stk.top();
                stk.pop();
                maxArea=max(maxArea,pair.first*(i-pair.second));
                lastIndex=pair.second;
            }
            stk.push({heights[i],lastIndex});
            }else{
                stk.push({heights[i],i});
            }
        }
        while(!stk.empty()){
            auto pair=stk.top();
            stk.pop();
            maxArea=max(maxArea,pair.first*((int)heights.size()-pair.second));
        }
        return maxArea;
    }
};
