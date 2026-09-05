class Solution {
    vector<string>res;
    unordered_map<char, string> digitToChar = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
};
public:
    vector<string> letterCombinations(string digits) {
       if(digits.empty())return res;
       helper(0,"",digits);
       return res;

    }
    void helper(int i,string curr,string &digits){
        if(curr.size()==digits.size()){
            res.push_back(curr);
            return;
        }
        string letter=digitToChar[digits[i]];
        for(char c:letter){
            helper(i+1,curr+c,digits);
        }

    }
 
};
