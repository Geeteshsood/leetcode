class Solution {
public:
    
    string addBinary(string a, string b) {
        
        string str;
        int m = a.size() , n  = b.size() , carry = 0;
        int i = m-1 , j = n-1;
        bool f1 = false , f2 = false;
        
        while(i >=0 || j >=0 || carry){
            
             int sum = 0;
            
             if(i >= 0){
                 sum ^= (a[i]-'0');
                 
                 if(1 & (a[i] - '0'))f1 = true;
                 else f1 = false;
                 
                 i--;
             }
             else f1 = false;
            
             if(j >= 0){
                 sum ^= (b[j]-'0');
                 
                 if(1 & (b[j] - '0'))f2 = true;
                 else f2 = false;
                 
                 j--;
             }
             else f2 = false;
            
             sum ^= carry;
            
             str += sum + '0';
             
             if(carry && (f1 || f2))carry = 1;
             else if(f1 && f2)carry = 1;
             else carry = 0;
            
        }
        
        reverse(str.begin(),str.end());
        
      return str;  
    }
};