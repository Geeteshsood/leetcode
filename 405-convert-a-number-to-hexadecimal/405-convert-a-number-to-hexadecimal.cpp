class Solution {
public:
    string toHex(int num) {
        
        string ans,str = "0123456789abcdef";
        
        for(int i=0;i<8;i++){
           
           ans = str[num & (0xf)] + ans;
           num = num>>4; 
        }
        
        for(int i=0;i<8;i++){
            if(ans[i] != '0'){
                return ans.substr(i);
            }
        }
        
        return "0";
    }
};