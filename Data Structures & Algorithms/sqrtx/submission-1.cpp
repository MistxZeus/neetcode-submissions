class Solution {
public:
    int mySqrt(int x) {
        int l=0,h=x;
        int res=0;
        while(l<=h){
            long long mid=l+(h-l)/2;
            if(mid*mid<x){
                res=mid;
                l=mid+1;
            }
            else if(mid*mid>x){
                h=mid-1;
            }
            else{
                return mid;
            }
        }
        return res;
    }
};