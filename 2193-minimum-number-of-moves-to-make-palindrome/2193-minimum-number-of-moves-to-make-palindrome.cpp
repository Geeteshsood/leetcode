class Solution {
public:
    
    int find(string s){
        
        int n = s.size();
        
        // cout<<s<<endl;
        
        if(n == 0){
            return 0;
        }
          
        if(s[0] == s[n-1]){
            return find(s.substr(1,n-2));
        }
        else{
            
            vector<int> first(26,-1),last(26,-1);
            
            for(int i=0;i<n;i++){
                if(first[s[i]-'a'] == -1)first[s[i]-'a'] = i;
                last[s[i]-'a'] = i;
            }
            
            int ch = -1 , mini = INT_MAX;
            
            for(int i=0;i<26;i++){
                if(first[i] != -1 && last[i] != -1){
                    int moves = first[i] + n - last[i] - 1;
                    if(moves < mini){
                        mini = moves;
                        ch = i;
                    }
                }
            }
            
            if(ch != -1){
                // cout<<ch<<endl;
             string p;
             if(first[ch] > 0 )p += s.substr(0,first[ch]);
             if(last[ch]-first[ch] > 1)p += s.substr(first[ch]+1,last[ch]-first[ch] - 1);
             if(last[ch]+1 < n)p += s.substr(last[ch] + 1);
                
             // cout<<p<<endl;
            
             return mini + find(p);
                
            }
        }
        
        return 0;
    }
    
    int minMovesToMakePalindrome(string s) {
        
        int n = s.size();
        return find(s);
        
    }
};