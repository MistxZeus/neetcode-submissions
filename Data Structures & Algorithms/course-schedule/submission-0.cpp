class Solution {
    unordered_map<int,vector<int>>adjList;
    unordered_set<int>visit;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(vector<int>preq:prerequisites){
            int src=preq[0],dst=preq[1];
            adjList[src].push_back(dst);
        }
        for(int i=0;i<numCourses;i++){
            
            if(!dfs(i))return false;
            
        }
        return true;
    }
    bool dfs(int i){
        if(visit.count(i))return false;
        if(adjList[i].empty())return true;
        visit.insert(i);
        for(int neighbours:adjList[i]){
            if(!dfs(neighbours))return false;
        }
        visit.erase(i);
        adjList[i].clear();
        return true;
    }
};
