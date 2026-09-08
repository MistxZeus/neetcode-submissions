class Solution {
    unordered_set<int>cols;
    unordered_set<int>posDiag;
    unordered_set<int>negDiag;
    int res;
public:
    int totalNQueens(int n) {
        
        res=0;
        backtrack(0,n);
        return res;
    }
    void backtrack(int i,int n){
        if(i==n){
            res++;
            return;
        }
        for(int c=0;c<n;c++){
            if(cols.count(c)||posDiag.count(i+c)||negDiag.count(i-c))continue;
            cols.insert(c);
            posDiag.insert(i+c);
            negDiag.insert(i-c);
            backtrack(i+1,n);
            cols.erase(c);
            posDiag.erase(i+c);
            negDiag.erase(i-c);
            
        }
    }
};