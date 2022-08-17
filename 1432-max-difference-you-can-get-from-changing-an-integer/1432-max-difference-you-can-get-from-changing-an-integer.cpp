class Solution {
public:
    int maxDiff(int num) {
        
        string s = to_string(num);
        string str = s;
        
        int n = s.size();
        
        int i = 0;
        while(i < n && s[i] == '9'){
            i++;
        }
        
        int ch = s[i]-'0';
        
        for(int i=0;i<n;i++){
            if(s[i]-'0' == ch){
                s[i] = 9 + '0';
            }
        }
        
        i = 0;
        while(i < n && str[i]-'0' <= 1){
            i++;
        }
        
        ch = str[i]-'0';
        
        int x = 1;
        
        if(i < n-1 && i != 0)x = 0;
       
           ch = str[i]-'0';
         
           for(;i<n;i++){
               if(str[i]-'0' == ch){
                   str[i] = x + '0';
               }
           }
        
        int a = stoi(s);
        int b = stoi(str);
        
        return abs(b-a);
    }
};