class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total=accumulate(nums.begin(),nums.end(),0);
        if(total%k!=0)return false;
        int target=total/k;
        sort(nums.rbegin(),nums.rend());
        vector<int>subsets(k,0);
        return dfs(0,target,nums,subsets,k);
    }
    bool dfs(int i,int target,vector<int>&nums,vector<int>subsets,int k){
        if(i==nums.size()){
            return true;
        }
        for(int j=0;j<k;j++){
            if(nums[i]+subsets[j]<=target){
                 subsets[j]+=nums[i];
                 if(dfs(i+1,target,nums,subsets,k))return true;
                 subsets[j]-=nums[i];
            }
            if(subsets[j]==0)break;
        }
        return false;
    }
};