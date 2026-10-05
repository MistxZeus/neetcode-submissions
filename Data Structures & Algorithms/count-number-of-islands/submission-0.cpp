class Solution {
    set<pair<int,int>>visited;
public:
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int rows=grid.size(),cols=grid[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(grid,i,j);
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<char>>&grid,int r,int c){
        int rows=grid.size(),cols=grid[0].size();
        if(min(r,c)<0||r==rows||c==cols||visited.count({r,c})||grid[r][c]=='0'){
            return;
        }
        visited.insert({r,c});
     
        dfs(grid,r+1,c);
        dfs(grid,r-1,c);
        dfs(grid,r,c+1);
        dfs(grid,r,c-1);
        visited.erase({r,c});
        grid[r][c]='0';
    }
};
