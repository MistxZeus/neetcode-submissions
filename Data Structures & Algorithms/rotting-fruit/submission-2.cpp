class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows=grid.size(),cols=grid[0].size();
        
        queue<pair<int,int>>rotten;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==2){
                    rotten.push({i,j});
                    
                }
            }
        }
        int length=0;
        while(rotten.size()){
            int queueLength=rotten.size();
            bool inc=false;
            for(int i=0;i<queueLength;i++){
            pair<int,int>curr=rotten.front();
            rotten.pop();
            int r=curr.first,c=curr.second;
            int neighbours[4][2]={
                {r+1,c},{r-1,c},{r,c+1},{r,c-1}
            };
            for(int j=0;j<4;j++){
                int rd=neighbours[j][0],cd=neighbours[j][1];
                if(min(rd,cd)<0||rd==rows||cd==cols||grid[rd][cd]!=1){
                    continue;
                }
                grid[rd][cd]=2;
                
                rotten.push({rd,cd});
                inc=true;
            }
            }
            if(inc)length++;
        }
        bool flag=false;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1)flag=true;
            }
        }
        if(flag)return -1;
        return length;
    }
};
