class Solution {
public:
    int shortestPath(vector<vector<int>>& grid) {
         int rows=grid.size(),cols=grid[0].size();
         if(grid[0][0] == 1 || grid[rows-1][cols-1] == 1) return -1;
         vector<vector<int>>visited(rows,vector<int>(cols,0));
         queue<pair<int,int>>queue;
         queue.push(pair<int,int>(0,0));
         visited[0][0]=1;
         int length=0;
         while(queue.size()){
            int queueLength=queue.size();
            for(int i=0;i<queueLength;i++){
                pair<int,int>curr=queue.front();
                queue.pop();
                int r=curr.first,c=curr.second;
                if(r==rows-1&&c==cols-1){
                    return length;
                }
                int neighbours[4][2]={{r,c+1},{r,c-1},{r+1,c},{r-1,c}};
                for(int j=0;j<4;j++){
                    int newR=neighbours[j][0],newC=neighbours[j][1];
                    if(min(newR,newC)<0||newR==rows||newC==cols||visited[newR][newC]==1||grid[newR][newC]==1)continue;
                    queue.push({newR,newC});
                    visited[newR][newC]=1;
                }

            }
            length++;
         }
         return -1;
    }
};

