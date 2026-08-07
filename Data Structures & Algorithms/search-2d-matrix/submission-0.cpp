class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        int c=matrix[0].size();
        int row=-1;
        int top=0,bot=r-1;
        while(top<=bot){
            int mid=(top+bot)/2;
            if(target>matrix[mid][c-1])top=mid+1;
            else if(target<matrix[mid][0])bot=mid-1;
            else {
                row=mid;
                break;
            }
        }
        if(row==-1)return false;
        int l=0,h=c-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(target==matrix[row][mid])return true;
            else if(target>matrix[row][mid])l=mid+1;
            else h=mid-1;
        }
        return false;
    }
};
