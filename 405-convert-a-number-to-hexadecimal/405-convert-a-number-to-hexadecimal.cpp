class Solution {
public:
    string toHex(int num){
        
        string str;
        
        string res = "0123456789abcdef";
         
        for(int bit=4;bit<32;bit+=4){
            
             int x = 1<<(bit);
             x = x - 1;
             x = num & x;
             x = x>>(bit-4);
            
             if(x<0)x = x^(0xfffffff0);
            
             str += res[x];
        }  
        
        int x = ~0;
        x = x & num;
        
        x = x>>28;
        if(x<0)x = x^(0xfffffff0);
        
        str += res[x];
        
        reverse(str.begin(),str.end());
        
        for(int i=0;i<8;i++){
            if(str[i] != '0'){
               return str.substr(i);
            }
        }
        
        return "0";
    }
};