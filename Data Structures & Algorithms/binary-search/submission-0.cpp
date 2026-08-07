class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,h=n-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]==target)return mid;
            else if(nums[mid]<target)l++;
            else h--;
        }
        return -1;
    }
};
