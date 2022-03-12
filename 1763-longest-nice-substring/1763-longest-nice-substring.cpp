class Solution {
public:
    
    bool check(string &s,int x,int y){
        // cout<<x<<" "<<y<<endl;
        vector<int> low(26),upp(26);
        
        for(int i=x;i<=y;i++){
            if(isupper(s[i]))upp[s[i]-'A']++;
            else low[s[i]-'a']++;
        }
        
        for(int i=0;i<26;i++){
            if(low[i] > 0 && upp[i] == 0)return false;
            if(upp[i] > 0 && low[i] == 0)return false;
        }
        
        return true;
    }
    
    string longestNiceSubstring(string s) {
        
        int n = s.size();
        int val = INT_MIN , ch = -1;
        
        for(int g=0;g<n;g++){
            for(int i=0,j=g;i<n && j<n;i++,j++){
                
                if(check(s,i,j)){
                    if(g > val){
                        val = g;
                        ch = i;
                    }
                }
                
            }
        }
        
        if(ch == -1)return "";
        
      return s.substr(ch,val+1);
    }
};