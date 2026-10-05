class Solution {
    set<pair<int,int>> visited;   
public:
    int countPaths(vector<vector<int>>& grid) {
         
         return dfs(grid,0,0);
    }
    int dfs(vector<vector<int>>&grid,int r,int c){
         int rows=grid.size(),cols=grid[0].size();
         if(min(r,c)<0||r==rows||c==cols||visited.count({r,c})||grid[r][c]==1){
            return 0;
         }
         if(r==rows-1&&c==cols-1){
            return 1;
         }
         visited.insert({r,c});
         int count=0;
         count+=dfs(grid,r+1,c);
         count+=dfs(grid,r-1,c);
         count+=dfs(grid,r,c+1);
         count+=dfs(grid,r,c-1);

         visited.erase({r,c});
         return count;
    }
};
