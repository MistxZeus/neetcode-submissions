class Solution {
int rows,cols; 
vector<vector<int>>visited;
public:
    bool exist(vector<vector<char>>& board, string word) {
        rows=board.size(),cols=board[0].size();
        visited=vector<vector<int>>(rows,vector<int>(cols,0));
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(dfs(board,word,r,c,0))return true;
            }
        }
        return false;
        
    }
    bool dfs(vector<vector<char>>&board,string word,int r,int c,int i){
        if(min(r,c)<0||r>=rows||c>=cols||visited[r][c]==1||board[r][c]!=word[i]){
            return false;
        }
        if(i==word.length()-1){
            return true;
        }
        visited[r][c]=1;
        bool res = dfs(board, word, r + 1, c, i + 1) ||
                   dfs(board, word, r - 1, c, i + 1) ||
                   dfs(board, word, r, c + 1, i + 1) ||
                   dfs(board, word, r, c - 1, i + 1);
        visited[r][c]=0;
        
        return res;
    }

};
