class Solution {
public:
    
    string addBinary(string a, string b) {
        
        string str;
        int m = a.size() , n  = b.size() , carry = 0;
        int x = 0 , y = 0,i = m-1 , j = n-1;
        
        while(i >=0 || j >=0){
            
             // cout<<i<<" "<<j<<" "<<carry<<endl;
            
             if(i >= 0)x = a[i]-'0',i--;
             else x = 0;
            
             if(j >= 0)y = b[j]-'0',j--;
             else y = 0;
            
            int sum = x + y + carry;
            
            carry = sum/2;
            str += sum%2 + '0';
            
        }
        
        if(carry)str += "1";
        
        reverse(str.begin(),str.end());
        
      return str;  
    }
};