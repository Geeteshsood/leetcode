class Solution {
public:
    
    int compareVersion(string s1, string s2) {
        
        int m = s1.size() , n = s2.size();
        
        int i = 0 , j = 0;
        
        for(;i<m || j<n;i++,j++){
            
            int lval = 0;
            
            while(i < m && s1[i]!='.'){
               lval = lval*10 + (s1[i]-'0'); 
               i++;
            }
            
            int rval = 0;
           
            while(j < n && s2[j]!='.'){
               rval = rval*10 + (s2[j]-'0'); 
               j++;
            }
            
            if(lval < rval)return -1;
            else if(lval > rval)return 1;
        }

     return 0; 
    }
};