class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>res;
        int l=0;
        
        for(int r=k-1;r<nums.size();r++){
            int max_element=INT_MIN;
             for(int i=l;i<=r;i++){
                  max_element=max(max_element,nums[i]);
            }
            l++;
            res.push_back(max_element);
        }
        return res;
    }
    
};
