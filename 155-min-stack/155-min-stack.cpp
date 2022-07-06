class MinStack {
public:
    typedef long long ll;
    
    stack<ll> st;
    ll mini = INT_MAX;
    
    MinStack() {
        
    }
    
    void push(int val) {
        
        int x = val;
        
        if(st.empty()){
            mini = val;
            st.push(val);
        }
        else if(val < mini){
             st.push(2ll*(ll)val - mini);
             mini = x;
        }
        else st.push(val);
    }
    
    void pop() {
        
        if(st.top() < mini){
            mini = 2*mini - st.top();
        }
        
        st.pop();
    }
    
    int top() {
        
        if(st.top() < mini){
            return mini;
        }
        
        return st.top();
    }
    
    int getMin() {
        
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */