class MyHashMap {
    private:
    vector<pair<int,int>>v;
public:
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
       auto it=find_if(v.begin(),v.end(),[key](const pair<int,int>&p){return p.first==key;});
       if(it==v.end())v.push_back({key,value});
       else it->second=value;
    }
    
    int get(int key) {
        auto it=find_if(v.begin(),v.end(),[key](const pair<int,int>&p){return p.first==key;});
        if(it!=v.end())return it->second;
        else return -1;
    }
    
    void remove(int key) {
        auto it=find_if(v.begin(),v.end(),[key](const pair<int,int>&p){return p.first==key;});
        if(it!=v.end()) v.erase(it);
        
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */