class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=(m+n-1),j=m,k=n;
        while(j>0&&k>0){
            if(nums1[j-1]>nums2[k-1]){
                nums1[i--]=nums1[j-1];
                j--;
            }else{
                nums1[i--]=nums2[k-1];
                k--;
            }
        }
       //clever trick since num1 already contains elements in a sorted manner 
       //any elements left uncompared will be already sorted in place no need to fill them
        while(k>0){
            nums1[i--]=nums2[k-1];
            k--;
        }

    }
};