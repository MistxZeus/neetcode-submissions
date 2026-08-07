class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int buy=prices[0];
        int max_profit=0;
        for(int i=1;i<n;i++){
            int sell=prices[i]-buy;
            if(sell>0){
                max_profit=max(max_profit,sell);
            }
            else{
                buy=prices[i];
            }
        }
        return max_profit;
    }
};
