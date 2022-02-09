class Solution {
public:
    
    string addBinary(string a, string b) {
        
        string str;
        int carry = 0 , sum = 0;
        int i = a.size()-1 , j = b.size()-1;
        
        while(i >=0 || j >=0 || carry){
            
             int x = 0 , y = 0;
            
             if(i >= 0){
                 x = a[i]-'0';
                 i--;
             }
            
             if(j >= 0){
                 y = b[j]-'0';
                 j--;
             }
            
             sum = x^y^carry;
            
             str += sum + '0';
             
             carry = (x | y) && (x | carry) && (y | carry);
        }
        
        reverse(str.begin(),str.end());
        
      return str;  
    }
};