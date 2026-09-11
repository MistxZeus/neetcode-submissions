class PrefixTree {
    unordered_map<char,PrefixTree*>children;
    bool word=false;
    
public:
    PrefixTree() {
        
    }
    
    void insert(string word) {
        PrefixTree *curr=this;
        for(char c:word){
            if(curr->children.count(c)==0){
                curr->children[c]=new PrefixTree();
            }
            curr=curr->children[c];
        }
        curr->word=true;
    }
    
    bool search(string word) {
        PrefixTree *curr=this;
        for(char c:word){
            if(curr->children.count(c)==0){
                return false;
            }
            curr=curr->children[c];
        }
        return curr->word;
    }
    
    bool startsWith(string prefix) {
        PrefixTree *curr=this;
        for(char c:prefix){
            if(curr->children.count(c)==0){
                return false;
            }
            curr=curr->children[c];
        }
        return true;
    }
};
