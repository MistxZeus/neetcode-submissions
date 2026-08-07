class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string prefix="";
        int i=0;
        while(i<min(strs[0].size(),strs[strs.size()-1].size())){
            if(strs[0][i]!=strs[strs.size()-1][i])break;
            i++;
        }
        prefix=strs[0].substr(0,i);
        return prefix;

    }
};