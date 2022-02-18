class Solution {
public:
    string removeKdigits(string nums, int k) {
        
        int n = nums.size();
        string str;
        
        for(int i=0;i<n;i++){
            
            while(k > 0 && str.size() && ((nums[i]-'0') < (str.back()-'0'))){
                str.pop_back();
                k--;
            }
            
            str += nums[i]; 
        }
        
        int len = str.size() , i = 0;
        
        while(i < len && str[i] == '0')i++;
        
        if(i>=(len-k))return "0";
            
        return str.substr(i,len-k-i);
    }
};