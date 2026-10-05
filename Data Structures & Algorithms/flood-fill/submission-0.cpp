class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int original=image[sr][sc];
        if(original==color)return image;
        dfs(image,original,sr,sc,color);
        return image;
    }
    void dfs(vector<vector<int>>&image,int original,int r,int c,int color){
        int rows=image.size(),cols=image[0].size();
        if(min(r,c)<0||r==rows||c==cols||image[r][c]!=original)return;
        image[r][c]=color;
        dfs(image,original,r+1,c,color);
        dfs(image,original,r-1,c,color);
        dfs(image,original,r,c+1,color);
        dfs(image,original,r,c-1,color);
    }
};