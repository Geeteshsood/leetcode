class Solution {
public:
    typedef long long ll;
    
    string convertToTitle(int n) {
        
        ll val = 1;
        string str;
        
        while(n){
          
           int x = (n-1)%26;
           
           str +=  x + 'A';
            
           n = (n-1)/26;
        }
        
        reverse(str.begin(),str.end());
        
      return str;  
    }
};