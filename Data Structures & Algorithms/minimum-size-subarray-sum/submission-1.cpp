class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0;
        int len=INT_MAX;
        int sum=0;
        
        while(r<n){
          sum+=nums[r];
          r++;
          while(sum>=target){
            len=min(len,r-l);
            sum-=nums[l];
            l++;
          }
          
        }
       
        return len == INT_MAX ? 0 : len;
        
    }
};