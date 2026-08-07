class Solution {
    private:
    bool can(const vector<int>&nums,int k,int target){
        int arrays=1,curr=target;
        for(int n:nums){
            if(curr-n<0){
                arrays++;
                if(arrays>k){
                    return false;
                }
                curr=target;
            }
            curr-=n;
        }
        return true;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int l=*max_element(nums.begin(),nums.end());
        int r=accumulate(nums.begin(),nums.end(),0);
        int res=r;
        while(l<=r){
            int target=l+(r-l)/2;
            if(can(nums,k,target)){
                res=target;
                r=target-1;
            }
            else{
                l=target+1;
            }
        }
        return res;
    }
};