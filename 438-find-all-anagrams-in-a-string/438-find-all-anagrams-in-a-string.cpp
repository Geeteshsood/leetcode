class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        int m = s.size() , n = p.size();
        vector<int> ans;
        
        vector<int> mp1(26,0);
        vector<int> mp2(26,0);
        
        if(n > m)return {};
        
        for(int i=0;i<n;i++){
            mp2[p[i]-'a']++;
        }
        
         for(int i=0;i<n;i++){
            mp1[s[i]-'a']++;
        }
        
        if(mp1 == mp2)ans.push_back(0);
        
        for(int i=n;i<m;i++){
            
            mp1[s[i-n]-'a']--;
            mp1[s[i]-'a']++;
            
            if(mp1 == mp2)ans.push_back(i-n+1);
        }
      
        return ans;
    }
};