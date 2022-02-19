class Solution {
public:
    
    int find(int i,vector<string>& stickers,vector<vector<int>> &dp,int mask,string &target){
        
        int n = stickers.size() , m = target.size();

        if(!mask)return 0;
        else if(i == n)return INT_MAX/2;
        
        if(dp[mask][i] != -1)return dp[mask][i];
        
        int mp[26]={0};
        
        for(auto &ch : stickers[i]){
             mp[ch-'a']+=1;
        }
        
        int nmask = 0;
        
        for(int bit=0;bit<m;bit++){
               
            if(mask & (1<<bit)){
                if(mp[target[bit]-'a']){
                   mp[target[bit]-'a']-=1;
                }
                else{
                    nmask |= (1<<bit);
                }
            }
        }

        if(nmask == mask)return dp[mask][i] = find(i+1,stickers,dp,mask,target);
        
        int x = find(i+1,stickers,dp,mask,target);
        int y = 1 + find(i,stickers,dp,nmask,target);
        
        return dp[mask][i] = min(x,y);
    }
    
    int minStickers(vector<string>& stickers, string target) {
        
        int mask=1;
        for(int i=0;i<target.length();i++)
        {
            mask=mask*2;
        }
        mask-=1;
        
        vector<vector<int>> dp(mask + 1,vector<int> (stickers.size() + 1,-1));
        
        int x = find(0,stickers,dp,mask,target);
        
        if(x == INT_MAX/2)x = -1;
        
        return x;
    }
};