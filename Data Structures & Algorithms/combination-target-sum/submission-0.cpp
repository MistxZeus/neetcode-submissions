class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>curr;
        vector<vector<int>>combs;
        helper(0, 0, target, nums, curr, combs);
        return combs;
    }
    void helper(int start, int sum, int target, vector<int>& nums, vector<int>& curr, vector<vector<int>>& combs){
        if(sum > target){
            return;
        }
        if(sum == target){
            combs.push_back(curr);
            return;
        }
        for(int i = start; i < nums.size(); i++){
            curr.push_back(nums[i]);
            helper(i, sum + nums[i], target, nums, curr, combs);
            curr.pop_back();
        }
    }
};