class Solution {
public:
    int distinctEchoSubstrings(string s) {
        
        unordered_set<string> se;
        
        int n = s.length();
        
        for(int len=1;len<=n/2;len++){
            
            int cnt = 0;
            
            for(int j=0;j+len<n;j++){
                
                if(s[j] == s[j+len]){
                    cnt++;
                }
                else cnt = 0;
                
                if(cnt == len){
                    string str = s.substr(j-len+1,len);
                    if(!se.count(str))
                        se.insert(str);
                    cnt--;
                }
            }
        }
        
      return se.size();
    }
};