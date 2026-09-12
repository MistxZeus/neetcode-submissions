class TrieNode{
    public:
    unordered_map<char,TrieNode*>children;
    bool word;
    TrieNode():word(false){}
};

class WordDictionary {
    public:
    TrieNode*root;

    WordDictionary(): root(new TrieNode()) {}

    
    void addWord(string word) {
        TrieNode*curr=root;
        for(char c:word){
            if(curr->children.count(c)==0){
                curr->children[c]=new TrieNode();
            }
            curr=curr->children[c];
        }
        curr->word=true;
    }
    
    bool search(string word) {
        return dfs(word,0,root);
         
    }
    bool dfs(string&word,int j,TrieNode*root){
        TrieNode*curr=root;
        for(int i=j;i<word.size();i++){
            char c=word[i];
            if(c=='.'){
                for(auto& pair:curr->children){
                    if(pair.second!=nullptr&&dfs(word,i+1,pair.second)){
                        return true;
                    }
                }
                return false;
            }
            else{
                if(curr->children.count(c)==0){
                    return false;
                }
                curr=curr->children[c];
            }
        }
        return curr->word;
    }
  
};
