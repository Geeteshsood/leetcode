class Solution {
public:
    string removeOuterParentheses(string s) {
        
        string str;
        int n = s.size();
        int cnt = 0 , i = 0;
        
        while(i < n){
            
            if(s[i] == '(')cnt++;
            else cnt--;
            
            s[i] = ' ';
            
            for(int j=i+1;j<n;j++){
                
                if(s[j] == '(')cnt++;
                else cnt--;
                
                if(cnt == 0){
                    s[j] = ' ';
                    i = j+1;
                    break;
                }
                
                str += s[j];
            }
        }
        
       return str;       
    }
    
};