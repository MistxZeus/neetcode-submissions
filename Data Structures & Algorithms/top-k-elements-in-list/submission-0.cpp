class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>count;
        for(int i=0;i<nums.size();i++){
            count[nums[i]]++;
        }
        vector<vector<int>>freq(nums.size()+1);
        for(auto it:count){
            freq[it.second].push_back(it.first);
        }
        vector<int>res;
        for(int i=freq.size()-1;i>0;i--){
            for(int n :freq[i]){
                res.push_back(n);
            }
            if(res.size()==k){
                return res;
            }
        }
    }
   
};
