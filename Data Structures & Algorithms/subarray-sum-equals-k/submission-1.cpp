class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>prefixSum;
        prefixSum[0]=1;
        int currentSum=0;
        int res=0;
        for(int i=0;i<n;i++){
            currentSum+=nums[i];
            int diff=currentSum-k;
            if(prefixSum.count(diff)){
                  res+=prefixSum[diff];
            }
            prefixSum[currentSum]++;
        }
        return res;
    }
};