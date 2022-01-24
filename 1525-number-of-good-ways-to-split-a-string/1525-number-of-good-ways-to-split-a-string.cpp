class Solution {
public:
    int numSplits(string s) {
        
        int n = s.size() , cnt = 0;
        
        vector<int> left(n),right(n);
        
        vector<bool> vis(26,false);
        
        for(int i=0;i<n;i++){
            if(!vis[s[i]-'a']){
                cnt++;
                vis[s[i]-'a'] = true;
            }    
            left[i] = cnt;
        }
        
        vis = vector<bool> (26,false);
        
        cnt = 0;
        for(int i=n-1;i>=0;i--){
            if(!vis[s[i]-'a']){
                cnt++;
                vis[s[i]-'a'] = true;
            }    
            right[i] = cnt;
        }
        
        cnt = 0;
        for(int i=0;i<n-1;i++){
            if(left[i] == right[i+1]){
                cnt++;
            }
        }
        
        return cnt;
    }
};