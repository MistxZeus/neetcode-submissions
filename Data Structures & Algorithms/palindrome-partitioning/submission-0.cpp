class Solution {
private:
vector<vector<string>>res;
bool isPalindrome(string s){
    string t=s;
    reverse(t.begin(),t.end());
    return(s==t);
}
public:
    vector<vector<string>> partition(string s) {
        vector<string>temp;
        dfs(0,1,s,temp);
        return res;

    }
    void dfs(int j,int i,string s,vector<string>temp){
        if(j==s.size()){
            res.push_back(temp);
            return;
        }
        if(i>s.size()){
            return;
        }
        if(isPalindrome(s.substr(j,i-j))){
            temp.push_back(s.substr(j,i-j));
            dfs(i,i+1,s,temp);
            temp.pop_back();
            
        }
        dfs(j,i+1,s,temp);
        return;
        

    }

};
