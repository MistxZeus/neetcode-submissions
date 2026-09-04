class Solution {
    vector<string>res;

public:
    vector<string> generateParenthesis(int n) {
        string temp="";
        helper(0,n,0,0,temp);
        return res;
    }
    void helper(int i,int n,int open,int close,string&s){
        if(close>open){
            return;
        }
        if(i==2*n&&open!=close){
            return;
        }
        if(i==2*n&&open==close){
            res.push_back(s);
            return;
        }
        s.append("(");
        open++;
        helper(i+1,n,open,close,s);
        open--;
        s.pop_back();

        s.append(")");
        close++;
        helper(i+1,n,open,close,s);
        close--;
        s.pop_back();
        

    }
};
