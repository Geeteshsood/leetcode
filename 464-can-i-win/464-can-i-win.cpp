class Solution {
public:
    
    bool find(int val,int digit,int player1,int mask,int n,int k,vector<int> &mp){
        
        if(val >= k){
            if(!player1)return true;
            else return false;
        }
        
        mask |= (1<<digit);
        // cout<<mask<<endl;
        if(mp[mask]!=-1)return mp[mask];
        
        for(int i=1;i<=n;i++){
            
            if(!(mask & (1<<i))){
                
                bool flag = find(val+i,i,!player1,mask,n,k,mp);
                
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
        
        int size = 1<<(n+1);
        vector<int> mp(size,-1);
        
        int maxReach = (n*(n+1))/2;
        if(maxReach < k)return false;
        
        if(k == 0)return true;
        
        return find(0,0,1,0,n,k,mp);
        
    }
};