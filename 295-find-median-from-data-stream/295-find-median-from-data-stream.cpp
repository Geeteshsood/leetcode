class MedianFinder {
public:
    
    priority_queue<int> maxi;
    priority_queue<int,vector<int>,greater<int>> mini;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
       int m = maxi.size() , n = mini.size();
        
       if(m == n){
           if(n > 0 && num > mini.top()){
               maxi.push(mini.top());
               mini.pop();
               mini.push(num);
           }
           else maxi.push(num);
       }
       else{
           if(num < maxi.top()){
               int val = maxi.top();
               maxi.pop();
               maxi.push(num);
               mini.push(val);
           }
           else mini.push(num);
       }
    }
    
    double findMedian() {
        
        int n = maxi.size() + mini.size();
        
        if(n%2 != 0){
            return maxi.top();
        }
       
        return (double)(maxi.top() + mini.top())/(double)2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */