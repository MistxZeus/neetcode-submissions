class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()==0||t.size()>s.size()){
            return "";
        }
        unordered_map<char,int>window,countT;
        for(char c:t){
            countT[c]++;
        }
        int have=0,need=countT.size();
        int min_len=INT_MAX;
        pair<int,int>res={-1,-1};
        int l=0;
        for(int r=0;r<s.size();r++){
            char c=s[r];
            window[c]++;
            if(countT.count(c)&&countT[c]==window[c])have++;
            while(have==need){
                if(min_len>r-l+1){
                    min_len=r-l+1;
                    res={l,r};
                }
                char b=s[l];
                window[b]--;
                if(countT.count(b)&&countT[b]>window[b])have--;
                l++;
            }
        }
        return min_len==INT_MAX?"":s.substr(res.first,min_len);
    }
};
