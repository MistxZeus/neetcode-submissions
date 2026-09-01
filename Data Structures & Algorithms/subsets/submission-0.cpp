class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>cur;
        vector<vector<int>>subset;
        helper(0,nums,cur,subset);
        return subset;
    }
    void helper(int i,vector<int>&nums,vector<int>&cur,vector<vector<int>>&subset){
        if(i>=nums.size()){
            subset.push_back((vector<int>)cur);
            return;
        }
        cur.push_back(nums[i]);
        helper(i+1,nums,cur,subset);
        cur.pop_back();

        helper(i+1,nums,cur,subset);
        return;
    }
};
