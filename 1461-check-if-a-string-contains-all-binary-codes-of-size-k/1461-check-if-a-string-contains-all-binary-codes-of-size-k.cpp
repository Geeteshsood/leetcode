class Solution {
public:
    bool hasAllCodes(string s, int k) {
       
        int n = s.size() , mask = 0 , fill = 0;
        
        if(k > n)return false;
        
        vector<bool> vis(1<<k,false);
        
        for(int i=0;i<k;i++){
            
            int bit = s[i]-'0';
            
            if(bit){
                mask = mask | (1<<i);
            }
        }

           if(!vis[mask]){
                fill++;
                vis[mask] = true;
            }
        
        for(int i=k;i<n;i++){
            
            mask = mask>>1;
            
            int bit = s[i]-'0';
            
            if(bit){
                mask = mask | (1<<(k-1));
            }

            if(!vis[mask]){
                fill++;
                vis[mask] = true;
            }
            
        }
        
        return fill == 1<<k;
    }
};