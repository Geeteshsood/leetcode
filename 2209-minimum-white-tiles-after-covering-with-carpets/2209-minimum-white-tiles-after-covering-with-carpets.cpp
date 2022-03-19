class Solution {
public:
    
    int dp[1001][1001];
    string s;
    
    int find(int i,int n,int len,int move,vector<int> &count){
       
        int m = s.size();
        
        if(move >= n)return 0;
        if(i >= m)return 0;
        
        while(i<m && s[i] == '0' )i++;
        
        if(i >= m)return 0;
        
        if(dp[i][move] != -1)return dp[i][move];
        
        int zero = 0;
        
        if(i+len-1 < m){
            if(i!=0)zero = count[i+len-1]-count[i-1];
            else zero = count[i+len-1];
        }
        else {
            if(i!=0)zero = count[m-1]-count[i-1];
            else zero = count[m-1];
        }
        
        // cout<<i<<" "<<zero<<endl;
        
        int x = zero + find(i+len,n,len,move+1,count);
        int y = find(i+1,n,len,move,count);
        
        return dp[i][move] = max(x,y);
    }
    
    int minimumWhiteTiles(string str, int n, int len) {
        
        s = str;
        memset(dp,-1,sizeof(dp));
        
        vector<int> count(str.size());
        
        int cnt  = 0;
        for(int i=0;i<str.size();i++){
            if(str[i] == '1'){
                cnt++;
            }
            count[i] = cnt;
        }
        int x =  find(0,n,len,0,count);
       
        return count[str.size()-1] - x;
    }
};