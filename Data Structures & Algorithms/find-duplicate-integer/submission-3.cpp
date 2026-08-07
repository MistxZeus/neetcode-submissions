class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int slow=0,fast=1;
        int res=-1;
        while(fast<nums.size()){
            if(nums[slow]==nums[fast]){
                res=nums[slow];
                break;
            }
            slow++;
            fast++;
        }
        return res;
    }
};
