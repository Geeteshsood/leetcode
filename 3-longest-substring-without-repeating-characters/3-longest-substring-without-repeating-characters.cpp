class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.size();
        vector<int> vis(256);
        
        int ans = 0,j=0;
        
        for(int i=0;i<n;i++){
            
            int ch = s[i]-' ';
            
            if(!vis[ch]){
                vis[ch] = true;
            }
            else{
                while(j < i && s[j] != s[i]){
                    vis[s[j]-' '] = false;
                    j++;
                }
                j++;
    
            }
            // cout<<i<<" "<<j<<endl;
            ans = max(ans,i-j+1);
        }
        
        return ans;
    }
};