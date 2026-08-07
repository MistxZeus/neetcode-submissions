class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>freq(nums.begin(),nums.end());
       
        int res=0;
        for(int num:nums){
            if(freq.find(num-1)==freq.end()){
                int current=num;
                int length=1;
                while(freq.find(current+1)!=freq.end()){
                    current++;
                    length++;
                }
                res=max(res,length);
            }
        }
        return res;
    }
};
