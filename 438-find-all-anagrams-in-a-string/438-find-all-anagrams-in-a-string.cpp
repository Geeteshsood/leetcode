class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        int m = s.size() , n = p.size();
        vector<int> ans;
        
        map<char,int> mp1,mp2;
        
        if(n > m)return {};
        
        for(int i=0;i<n;i++){
            mp2[p[i]]++;
        }
        
         for(int i=0;i<n;i++){
            mp1[s[i]]++;
        }
        
        if(mp1 == mp2)ans.push_back(0);
        
        for(int i=n;i<m;i++){
            
            if(mp1[s[i-n]] == 1){
                mp1.erase(s[i-n]);
            }
            else mp1[s[i-n]]--;
            
            mp1[s[i]]++;
            
            if(mp1 == mp2)ans.push_back(i-n+1);
            
        }
      
        return ans;
    }
};