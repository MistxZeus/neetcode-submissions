class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>freq1;
        for(char c:s1){
            freq1[c]++;
        }
        int n=s1.size()-1;
        int l=0,r=0+n;
        int m=s2.size();
        while(r<m){
            unordered_map<char,int>freq2;
            for(int i=l;i<=r;i++){
                 freq2[s2[i]]++;
            }
            if(freq1==freq2)return true;
            else{
                l++;
                r++;
            }
        }
        return false;
    }
};
