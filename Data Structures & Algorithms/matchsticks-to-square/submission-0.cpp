class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum=accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(sum%4!=0)return false;
        int length=sum/4;
        vector<int>sides(4,0);
        sort(matchsticks.rbegin(),matchsticks.rend());
        return backtrack(0,sides,length,matchsticks);
    }
    bool backtrack(int i,vector<int>&sides,int length,vector<int>&matchsticks){
        if(i==matchsticks.size())return true;

        for(int j=0;j<4;j++){
            if(matchsticks[i]+sides[j]<=length){
                sides[j]+=matchsticks[i];
                if(backtrack(i+1,sides,length,matchsticks))return true;
                sides[j]-=matchsticks[i];
            }
            if(sides[j]==0)break;

        }
        return false;
    }
};