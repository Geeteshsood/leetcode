class Solution {
public:
    
    bool canReach(string s, int mi, int mx){
        
        int sum  = 0 , n = s.size();
        int k = mx - mi + 1 ,x = 0 , y = 0;
        
        for(int i=1;i<mi;i++){
            s[i] = '1';
        }
        
        for(int i=mi;i<n;i++){
            
             x = s[i-mi]-'0';
            
             if(i-mx-1 >= 0)y = s[i-mx-1]-'0';
             else y = 0;
            
             sum += x - y;
            
             if(s[i] == '0' && sum == k){
                 s[i] = '1';
             }
            
        }
        
        return s[n-1] == '0';
    }
};