class MyQueue {
    private:
    stack<int>stk1;
    stack<int>stk2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        stk1.push(x);
    }
    
    int pop() {
        for(int i=stk1.size()-1;i>0;i--){
            stk2.push(stk1.top());
            stk1.pop();
        }
        int front=stk1.top();
        stk1.pop();
        while(!stk2.empty()){
            stk1.push(stk2.top());
            stk2.pop();
        }
        return front;
    }
    
    int peek() {
         for(int i=stk1.size()-1;i>0;i--){
            stk2.push(stk1.top());
            stk1.pop();
        }
        int front=stk1.top();
        
        while(!stk2.empty()){
            stk1.push(stk2.top());
            stk2.pop();
        }
        return front;
    }
    
    bool empty() {
        return stk1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */