class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>curset;
        vector<vector<int>>subsets;
        helper(0,nums,curset,subsets);
        return subsets;

    }
    void helper(int        i,vector<int>&nums,vector<int>&curset,vector<vector<int>>&subsets){
        if(i>=nums.size()){
            subsets.push_back((vector<int>)curset);
            return;
        }

        curset.push_back(nums[i]);
        helper(i+1,nums,curset,subsets);
        curset.pop_back();

        while(i+1<nums.size()&&nums[i]==nums[i+1]){
            i+=1;
        }
        helper(i+1,nums,curset,subsets);
        return;
    }
};
