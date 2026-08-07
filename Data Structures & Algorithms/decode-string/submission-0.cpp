class Solution {
public:
    string decodeString(string s) {
        vector<string>stk;
        for(char &c:s){
            if(c!=']'){
                stk.push_back(string(1,c));
            }else{
                string substr="";
                while(stk.back()!="["){
                    substr=stk.back()+substr;
                    stk.pop_back();
                }
                stk.pop_back();
                string k="";
                while(!stk.empty()&&isdigit(stk.back()[0])){
                    k=stk.back()+k;
                    stk.pop_back();
                }
                int repeatedCount=stoi(k);
                string repeated="";
                for(int i=0;i<repeatedCount;i++){
                    repeated+=substr;
                }
                stk.push_back(repeated);
            }
        }
        string res="";
        for(const string&part:stk){
            res+=part;
        }
        return res;
    }
};