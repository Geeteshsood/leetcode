class Solution {
public:
    
    unordered_map<string,bool> mp;
    
    bool find(string s,string t){

        if(mp.count(s+t)){
            return mp[s+t];
        }
        
        if(s == t)return mp[s+t] = true;
        
        int n = s.size();
        
        if(n == 1)return mp[s+t] = false;
        
        for(int k=1;k<n;k++){

           bool f1 = find(s.substr(0,k),t.substr(0,k)) && find(s.substr(k),t.substr(k));
           bool f2 = find(s.substr(0,k), t.substr(n-k)) && find(s.substr(k),t.substr(0,n-k));
            
          if(f1 || f2)return mp[s+t] = true;
        }
        
        return mp[s+t] = false;
    }
    
    
    bool isScramble(string s, string t) {
        
        int n = s.size();
        return find(s,t);
        
    }
};