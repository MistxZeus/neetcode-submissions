class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size()||t.size()==0)return "";
        unordered_map<char,int>countT,window;
        for(char c:t){
            countT[c]++;
        }
        int need=countT.size();
        int resLen=INT_MAX;
        pair<int,int>res={-1,-1};
        int have=0;
        int l=0;
        for(int r=0;r<s.size();r++){
            char c=s[r];
            window[c]++;
            if(countT.count(c)&&countT[c]==window[c]){
                have++;
            }
            while(have==need){
                if(resLen>r-l+1){
                    resLen=r-l+1;
                    res={l,r};
                }
                window[s[l]]--;
                if(countT.count(s[l])&&window[s[l]]<countT[s[l]])have--;
                l++;
            }
        }
        return resLen==INT_MAX?"":s.substr(res.first,resLen);
    }
};
