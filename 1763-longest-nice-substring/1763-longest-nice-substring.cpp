class Solution {
public:
    
    bool check(unordered_map<int,int> &mp){
        
//        for(int i=0;i<26;i++){
//            char c1 = i+'a' ,c2 = i+32 + 'A';
//            cout<<c1<<"="<<mp[i]<<" , "<<c2<<"="<<mp[i+32]<<endl;
//        }
        
        for(int i=0;i<26;i++){
            if(mp[i] > 0){
                if(mp[i + 32] == 0)return false;
            }
            else if(mp[i + 32] > 0){
                if(mp[i] == 0)return false;
            }
        }
        
        return true;
    }
    
    string longestNiceSubstring(string s) {
        
        int n = s.size() , st = -1 , x = -1;
        
        for(int len=1;len<=n;len++){
            
            unordered_map<int,int> mp;
            bool flag = true;
            
            for(int j=0;j<len;j++){
                int ch = (int)s[j];
                
                if(ch >= 97){
                    mp[s[j]-'a']++;
                }
                else mp[(s[j]-'A') + (32)]++;
            }
            
            if(check(mp) && flag)st = 0,flag = false,x = len;
            // cout<<" ** "<<endl;
            
            for(int j=len;j<n;j++){
                int ch = (int)s[j];
                if(ch >= 97){
                    mp[s[j]-'a']++;
                }
                else mp[(s[j]-'A') + (32)]++;
                
                int ch2 = (int)s[j-len];
                if(ch2 >= 97){
                    if(mp[s[j-len]-'a'] == 1)mp.erase(s[j-len]-'a');
                    else mp[s[j-len]-'a']--;
                }
                else{
                    if(mp[(s[j-len]-'A') + (32)] == 1)mp.erase((s[j-len]-'A') + (32));
                    else mp[(s[j-len]-'A') + (32)]--;
                }
                
                if(check(mp) && flag)st = j-len+1,flag = false,x = len;
                // cout<<" ** "<<endl;
            }
            
        }
        
        if(st == -1)return "";
        
        return s.substr(st,x);
    }
};