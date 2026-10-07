class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int rows=grid.size(),cols=grid[0].size();
        if(grid[0][0]==1||grid[rows-1][cols-1]==1)return -1;
        vector<vector<int>>visited(rows,vector<int>(cols,0));
        queue<pair<int,int>>queue;
        queue.push(pair<int,int>(0,0));
        visited[0][0]=1;
        int length=1;
        while(queue.size()){
            int queueLength=queue.size();
            for(int i=0;i<queueLength;i++){
                pair<int,int>curr=queue.front();
                queue.pop();
                int r=curr.first,c=curr.second;
                if(r==rows-1&&c==cols-1){
                    return length;
                }
                int neighbours[8][2]={
                    {r-1,c},{r+1,c},{r,c+1},{r,c-1},{r+1,c+1},{r-1,c-1},{r-1,c+1},{r+1,c-1}
                };
                for(int j=0;j<8;j++){
                    int rd=neighbours[j][0],cd=neighbours[j][1];
                    if(min(rd,cd)<0||rd==rows||cd==cols||visited[rd][cd]==1||grid[rd][cd]==1){
                        continue;
                    }
                    queue.push(pair<int,int>(rd,cd));
                    visited[rd][cd]=1;
                }
            }
            length++;
        }
        return -1;
    }
};