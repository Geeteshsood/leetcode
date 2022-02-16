class Solution {
public:
    
    bool find(int val,int digit,int player1,int mask,int n,int k,vector<int> &mp){
        
        if(val >= k){
            return !player1;
        }
        
        mask |= (1<<digit);
        
        if(mp[mask] != -1)return mp[mask];
        
        for(int i=1;i<=n;i++){
            
            if(!(mask & (1<<i))){
                
                bool flag = find(val+i,i,!player1,mask,n,k,mp);
                
                if(player1 == flag){
                    mp[mask] = flag;
                    mask = mask^(1<<digit);
                    return flag;
                }
  
            }
            
        }
        
        mp[mask] = !player1;
        
        mask = mask^(1<<digit);
        
        return !player1;
    }
    
    bool canIWin(int n, int k) {
        
        int size = 1<<(n+1);
        vector<int> mp(size,-1);
        
        int maxReach = (n*(n+1))/2;
        if(maxReach < k)return false;
        
        if(k == 0)return true;
        
        return find(0,0,1,0,n,k,mp);
        
    }
};