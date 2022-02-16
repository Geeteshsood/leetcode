class Solution {
public:
    
    unordered_map<int,int> mp;
    
    bool find(int val,int digit,int player1,int num,int n,int k){
        
        // cout<<digit<<" "<<!player1<<endl;
        
        if(val >= k){
            if(!player1)return true;
            else return false;
        }
        
        num = num | (1<<digit);
        
        if(mp.count(num))return mp[num];
        
        for(int i=1;i<=n;i++){
            
            if(!(num & (1<<i))){
                
                bool flag = find(val+i,i,!player1,num,n,k);
                
                if(player1 && flag){
                    mp[num] = true;
                    num = num^(1<<digit);
                    return true;
                }
                else if(!player1 && !flag){
                    mp[num] = false;
                    num = num^(1<<digit);
                    return false;
                }
            }
            
        }
        
        if(player1)mp[num] = false;
        else mp[num] = true;
        
        num = num^(1<<digit);
        
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