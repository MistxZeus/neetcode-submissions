class Solution {
    unordered_set<int>col;
    unordered_set<int>pos;
    unordered_set<int>neg;
    vector<vector<string>>res;
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        backtrack(0,n,board);
        return res;
    }
    void backtrack(int r,int n,vector<string>&board){
        if(r==n){
            res.push_back(board);
            return;
        }
        for(int c=0;c<n;c++){
            if(col.count(c)||pos.count(r+c)||neg.count(r-c)){
                continue;
            }
            col.insert(c);
            pos.insert(r+c);
            neg.insert(r-c);
            board[r][c]='Q';
            backtrack(r+1,n,board);
            col.erase(c);
            pos.erase(r+c);
            neg.erase(r-c);
            board[r][c]='.';
        }
    }
};
