class Solution {
public:
    int myAtoi(string s) {
        
        int n = s.size() , idx = 0 , sign = 1;
        
        for(idx;idx<n;idx++){
            if(s[idx] == ' ')continue;
            else break;
        }
        
        if(idx < n){
            if(s[idx] == '+')sign = 1,idx++;
            else if(s[idx] == '-')sign = -1,idx++;
        }
        
        long val = 0;
        bool neg = false;
        
        while(idx < n && isdigit(s[idx])){
            
            val = val*10 + (s[idx]-'0');
            
            if(sign == -1 && val > INT_MAX)return INT_MIN;
            else if(sign == 1 && val >= INT_MAX)return INT_MAX;
         
            idx++;
        }

        return sign*val;
    }
};