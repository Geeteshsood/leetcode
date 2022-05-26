class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        
        int n = s.size() , cnt = 0;
        
        string str,ans;
        
        for(int i=n-1;i>=0;i--){
            
            if(s[i] == '-')continue;
            
            char ch;
            
            if(s[i] >= 'a' && s[i] <= 'z'){
                ch = (s[i]-'a') + 'A';
            }
            else ch = s[i];
            
            str += ch;
            cnt++;
            
            if(cnt == k){
                str += '-';
                ans += str;
                cnt = 0;
                str = "";
            }
        }
        
        if(str.size())ans += str;
        
        reverse(ans.begin(),ans.end());
        
        if(ans[0] == '-')return ans.substr(1);
        
        return ans;
    }
};