class Solution {
    private:
    int res = 0;
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows=grid.size(),cols=grid[0].size();
        int count=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1){
                   int temp=0;
                   count=dfs(grid,i,j,temp);
                   res=max(res,count);
                }
            }
        }
        return res;
        
    }
    int dfs(vector<vector<int>>&grid,int r,int c,int &count){
        int rows=grid.size(),cols=grid[0].size();
        if(min(r,c)<0||r>=rows||c>=cols||grid[r][c]==0){
            return count;
        }
        grid[r][c]=0;
        count++;
        dfs(grid,r+1,c,count);
        dfs(grid,r-1,c,count);
        dfs(grid,r,c+1,count);
        dfs(grid,r,c-1,count);
        return count;
        
    }
};
