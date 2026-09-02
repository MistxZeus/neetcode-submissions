class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>curr;
        vector<vector<int>>combs;
        helper(0,0,target,candidates,curr,combs);
        return combs;
    }
    void helper(int i,int sum,int target,vector<int>&candidates,vector<int>&curr,vector<vector<int>>&combs){
        if(sum>target){
            return;
        }
        if(sum==target){
            combs.push_back(curr);
            return;
        }
        for(int j=i;j<candidates.size();j++){
            if(j > i && candidates[j] == candidates[j-1]) continue;
            curr.push_back(candidates[j]);
            helper(j+1,sum+candidates[j],target,candidates,curr,combs);
            curr.pop_back();
        }
    }
};
