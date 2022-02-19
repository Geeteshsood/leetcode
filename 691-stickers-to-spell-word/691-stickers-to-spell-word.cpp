class Solution {
public:
    
    
    
    
    int recurse(string &s,vector<string> &st,int mask,int i,vector<vector<int>> &dp)
    {   
        if(!mask)
            return 0;
        if(i==st.size())
            return INT_MAX/2;
        if(dp[mask][i]!=-1)
            return dp[mask][i];
        int mp[26]={0};
        for(int j=0;j<st[i].length();j++)
        {
            mp[st[i][j]-'a']+=1;
        }
        int newmask=0;
        for(int j=0;j<s.length();j++)
        {   
            int ith_bit=1<<j;
            if(mask & ith_bit)
            {
                if(mp[s[j]-'a'])
                {
                    mp[s[j]-'a']-=1;
                }
                else
                    newmask+=ith_bit;
            }
        }
        if(mask==newmask)
        {
            return dp[mask][i]=recurse(s,st,mask,i+1,dp);
        }
        int b=recurse(s,st,mask,i+1,dp);
        int a=recurse(s,st,newmask,i,dp)+1;
        return dp[mask][i]=min(a,b);
    }
    
    int minStickers(vector<string>& stickers, string target) {
        int mask=1;
        for(int i=0;i<target.length();i++)
        {
            mask=mask*2;
        }
        mask-=1;
        vector<vector<int>> dp(mask+1,vector<int> (stickers.size()+1,-1));
        int x=recurse(target,stickers,mask,0,dp);
        return x==INT_MAX/2?-1:x;
        
    }
};