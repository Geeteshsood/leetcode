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
            
            if(sum == 0)carry = 0, str = "0" + str;
            else if(sum == 1)carry = 0,str = "1" + str;
            else if(sum == 2)carry = 1,str = "0" + str;
            else if(sum == 3)carry = 1,str = "1" + str;
            
        }
        
        if(carry)str = "1" + str;
        
      return str;  
    }
};