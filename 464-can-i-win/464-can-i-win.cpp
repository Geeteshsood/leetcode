class Solution {
public:
    
    unordered_map<int,bool> mp;
    
    bool find(int val,int digit,int player1,int mask,int n,int k){
        
        if(val >= k){
            if(!player1)return true;
            else return false;
        }
        
        mask |= (1<<digit);
        
        if(mp.count(mask))return mp[mask];
        
        for(int i=1;i<=n;i++){
            
            if(!(mask & (1<<i))){
                
                bool flag = find(val+i,i,!player1,mask,n,k);
                
                if(player1 && flag){
                    mp[mask] = true;
                    mask = mask^(1<<digit);
                    return true;
                }
                else if(!player1 && !flag){
                    mp[mask] = false;
                    mask = mask^(1<<digit);
                    return false;
                }
            }
            
        }
        
        if(player1)mp[mask] = false;
        else mp[mask] = true;
        
        mask = mask^(1<<digit);
        
        if(player1)return false;
        
        return true;
    }
    
    bool canIWin(int n, int k) {
        
        int maxReach = (n*(n+1))/2;
        if(maxReach < k)return false;
        
        if(k == 0)return true;
        
        return find(0,0,1,0,n,k);
        
    }
};