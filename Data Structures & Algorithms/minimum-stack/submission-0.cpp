class MinStack {
    private:
    stack<int>stk1;
    stack<int>stk2;
   
public:
   
    MinStack() {
        
    }
    
    void push(int val) {
        stk1.push(val);
        if(stk2.size()==0)stk2.push(val);
        else{
            int current=stk2.top();
            stk2.push(min(current,val));
        }
        
    }
    
    void pop() {
        stk1.pop();
        stk2.pop();
    }
    
    int top() {
        return stk1.top();
    }
    
    int getMin() {
        return stk2.top();
    }
};
