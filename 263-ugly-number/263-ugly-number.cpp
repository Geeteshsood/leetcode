class Solution {
public:
    
    bool find(int n){
        
        if(n == 1)return true;
        
        bool flag = false;
        
        if(n % 2 == 0)flag = flag || find(n / 2);
        if(n % 3 == 0)flag = flag || find(n / 3);
        if(n % 5 == 0)flag = flag || find(n / 5);
        
     return flag;
    }
    
    bool isUgly(int n) {
      
       if(n <= 0)return false;
                   
       return find(n);
    }
};