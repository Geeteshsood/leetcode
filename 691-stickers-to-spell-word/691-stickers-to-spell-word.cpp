class Solution {
public:
    
    int find(int i,vector<string>& stickers,vector<vector<int>> &dp,int mask,string &target){
        
        int n = stickers.size() , m = target.size();

        if(mask == 0)return 0;
        else if(i == n)return INT_MAX;
        
        if(dp[i][mask] != -1)return dp[i][mask];
        
        vector<int> mp(26);
        
        for(auto &ch : stickers[i]){
             mp[ch-'a']++;
        }
        
        int nmask = 0;
        
        for(int bit=0;bit<m;bit++){
               
            if(mask & (1<<bit)){
                if(mp[target[bit]-'a']){
                   mp[target[bit]-'a']--;
                }
                else{
                    nmask = nmask | (1<<bit);
                }
            }
        }

        if(nmask == mask)return dp[i][mask] = find(i+1,stickers,dp,mask,target);
        
        int x = find(i+1,stickers,dp,mask,target);
        int y = find(i,stickers,dp,nmask,target);
        
        if(y != INT_MAX)y++;
        
        return dp[i][mask] = min(x,y);
    }
    
    int minStickers(vector<string>& stickers, string target) {
        
        int mask=1;
        for(int i=0;i<target.length();i++)
        {
            mask=mask*2;
        }
        mask-=1;
        
        vector<vector<int>> dp(stickers.size() + 1,vector<int> (mask + 1,-1));
        
        int x = find(0,stickers,dp,mask,target);
        
        if(x == INT_MAX)x = -1;
        
        return x;
    }
};