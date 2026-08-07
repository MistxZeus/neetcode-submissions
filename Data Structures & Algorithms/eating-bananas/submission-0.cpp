class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int max_val=*max_element(piles.begin(),piles.end());
        int l=1,r=max_val;
        int k=max_val;
        while(l<=r){
            int mid=l+(r-l)/2;
            long long hrs=0;
            for(int p:piles){
                hrs+=ceil(static_cast<double>(p)/mid);
            }
            if(hrs>h)l=mid+1;
            else if(hrs<=h){
                k=mid;
                r=mid-1;
            }
        }
        return k;

    }
};
