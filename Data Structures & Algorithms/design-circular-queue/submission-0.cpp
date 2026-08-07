class MyCircularQueue {
    int rear=-1,front=0,k=0,size=0;
    vector<int>v;
public:
    MyCircularQueue(int capacity) {
        k=capacity;
        v=vector<int>(k);
        
    }
    
    bool enQueue(int value) {
        if(isFull())return false;
        rear=(rear+1)%k;
        v[rear]=value;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())return false;
        front=(front+1)%k;
        size--;
        return true;
    }
    
    int Front() {
        if(isEmpty())return -1;
        else return v[front];
    }
    
    int Rear() {
        if(isEmpty())return -1;
        else return v[rear];
    }
    
    bool isEmpty() {
        if(size==0)return true;
        else return false;
    }
    
    bool isFull() {
        if(size==k)return true;
        else return false;
    }
};