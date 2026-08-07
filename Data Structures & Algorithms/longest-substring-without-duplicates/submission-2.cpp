class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==1)return 1;
        int n=s.size();
        int l=0,r=0;
        int max_len=0;
        unordered_set<char>window;
        while(r<n){
            if(window.count(s[r])){
               window.erase(s[l]);
               l++;
            }
            else{
                window.insert(s[r]);
                r++;
                max_len=max(max_len,r-l);
            }
       
        }
        return max_len;
    }
};
