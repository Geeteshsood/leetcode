class StockSpanner {
public:
    
    stack<pair<int,int>> st;
    int i=0;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        int span = 0;
        
        while(st.size() && price >= st.top().first){
            st.pop();
        }
        
        if(st.size())span = i - st.top().second;
        else span = i+1;
        
        st.push({price,i});
        
        i++;
        
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */