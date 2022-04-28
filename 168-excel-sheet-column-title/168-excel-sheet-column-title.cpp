class Solution {
public:
    typedef long long ll;
    
    string convertToTitle(int n) {
        
        ll val = 1;
        string str;
        
        while(n){
          
           val = val*26;
            
           ll x = (n-1)%val;
            
           char ch = (x/(val/26)) + 'A';
            
           str += ch;
            
           n = n-x-1;
        }
        
        reverse(str.begin(),str.end());
        
      return str;  
    }
};