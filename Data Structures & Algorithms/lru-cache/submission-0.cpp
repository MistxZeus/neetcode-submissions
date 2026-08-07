class ListNode{
    public:
    int key;
    int val;
    ListNode*prev;
    ListNode*next;
    ListNode(int k,int v):key(k),val(v),prev(nullptr),next(nullptr) {}
};

class LRUCache {
    private:
    unordered_map<int,ListNode*>cache;
    ListNode*left;
    ListNode*right;
    int size=0;
    int cap;
    void remove(ListNode*node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }
    void insert(ListNode*node){
        ListNode*temp=right->prev;
        temp->next=node;
        node->prev=temp;
        node->next=right;
        right->prev=node;
    }
public:
    LRUCache(int capacity) {
        left=new ListNode(0,0);
        right=new ListNode(0,0);
        left->next=right;
        right->prev=left;
        cap=capacity;
    }
    
    int get(int key) {
        if(cache.find(key)!=cache.end()){
            ListNode*node=cache[key];
            remove(node);
            insert(node);
            return node->val;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            ListNode*node=cache[key];
            node->val=value;
            remove(node);
            insert(node);
        }else{
            ListNode*node=new ListNode(key,value);
            cache.insert({key,node});
            insert(node);
            size++;
        }
        if(size>cap){
            ListNode*lru=left->next;
            cache.erase(lru->key);
            remove(lru);
            size--;
            delete lru;
        }
    }
};
