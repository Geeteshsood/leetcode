class Solution {
public:
    
    bool isvowel(char ch){
      return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    
    int findTheLongestSubstring(string s) {
        
        int n = s.size() , mask = 0 , len = 0;
        unordered_map<int,int> mp;
        mp[0] = -1;
        
        for(int i=0;i<n;i++){
            
            if(isvowel(s[i])){
                
                mask ^= (1<<(s[i]-'a'));
                
                if(mp.find(mask) == mp.end()){
                     mp[mask] = i;
                }
            }
            
            if(mp.find(mask) != mp.end()){
                len = max(len , i-mp[mask]);
            }
        }
      
        return len;
    }
};