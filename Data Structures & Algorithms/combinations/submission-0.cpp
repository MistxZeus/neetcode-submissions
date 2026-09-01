class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int>curr;
        vector<vector<int>>comb;
        helper(1,n,k,curr,comb);
        return comb;
    }
    void helper(int i,int n,int k,vector<int>&curr,vector<vector<int>>&comb){
        
        if(curr.size()==k){
            comb.push_back((vector<int>)curr);
            return;
        }
        if(i>n){
            return;
        }
        for(int j=i;j<n+1;j++){
            curr.push_back(j);
            helper(j+1,n,k,curr,comb);
            curr.pop_back();
        }
    }
};