class Solution {
public:
    // bit manipulation
    bool checkInclusion(string s1, string s2) {
        
        int m = s1.size() , n = s2.size();
        
        if(m > n)return false;
        
       unordered_map<char,int> dp,mp;
        
       for(auto &i : s1){
           dp[i]++;
       }
        
       for(int i=0;i<m;i++){
           mp[s2[i]]++;
       }
        
       if(dp == mp)return true;
        
       for(int i=m;i<n;i++){
           mp[s2[i]]++;
           
           mp[s2[i-m]]--;
           
           if(mp[s2[i-m]] == 0)mp.erase(s2[i-m]);
           
           if(dp == mp)return true;
       }
        
      return false;  
    }
};