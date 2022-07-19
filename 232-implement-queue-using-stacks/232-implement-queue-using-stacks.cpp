class MyQueue {
public:
    
    stack<int> inp,out;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        
        inp.push(x);
        
    }
    
    int pop() {
        
        if(out.empty()){
            while(inp.size()){
                out.push(inp.top());
                inp.pop();
            }
        }
        
        int ele = out.top();
        out.pop();
        
        return ele;
    }
    
    int peek() {
        
        if(out.empty()){
            while(inp.size()){
                out.push(inp.top());
                inp.pop();
            }
        }
        
        int ele = out.top();
        
        return ele;
        
    }
    
    bool empty() {
        
        return inp.empty() && out.empty();
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