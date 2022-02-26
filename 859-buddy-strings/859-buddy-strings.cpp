class Solution {
public:
    bool buddyStrings(string s, string goal) {
        
        if(s.size()!=goal.size())return false;
        int n = s.size(),x = - 1, y = -1;
        bool flag = false , set = false;
        int cnt = 0;
        vector<int> vis(26);
        
        for(int i=0;i<n;i++){
            if(!vis[s[i]-'a'])vis[s[i]-'a'] = true;
            else flag = true;
            
            if(s[i] != goal[i]){
                if(cnt == 0){
                    x = s[i]-'a';
                    y = goal[i]-'a';
                }
                if(cnt == 1){
                    set = ((y == s[i]-'a') && (x == goal[i]-'a'));
                }
                cnt++;
                if(cnt > 2)return false;
            }
        }
     
     return (cnt == 2 && set) || (cnt == 0 && flag);   
    }
};