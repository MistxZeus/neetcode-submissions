class Solution {
    vector<string>res;
    unordered_set<string>words;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string>temp;
        for(string w:wordDict){
            words.insert(w);
        }
        backtrack(0,1,s,temp);
        return res;
    }
    void backtrack(int j,int i,string&s,vector<string>&temp){
        if(j==s.length()){
            string result;
            for(int i=0;i<temp.size();i++){
                if(i>0)result+=" ";
                result+=temp[i];
            }
            res.push_back(result);
            return;
        }
         if(i>s.length()){
            return;
        }
       
        if(words.count(s.substr(j,i-j))){
            temp.push_back(s.substr(j,i-j));
            backtrack(i,i+1,s,temp);
            temp.pop_back();
        }
        backtrack(j,i+1,s,temp);
    }
};