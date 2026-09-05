class Solution {
    int res;
public:
    int subsetXORSum(vector<int>& nums) {
         res=0;
        vector<int>curSet;
        helper(0,nums,curSet);
        return res;
    }
    void helper(int i,vector<int>&nums,vector<int>&curSet){
        if(i==nums.size()){
            int sum=0;
            for(int num:curSet){
                 sum=sum^num;
            }
            res+=sum;
            return;
        }
        curSet.push_back(nums[i]);
        helper(i+1,nums,curSet);
        curSet.pop_back();

        helper(i+1,nums,curSet);
    }
};