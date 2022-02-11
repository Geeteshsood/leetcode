class Solution {
public:
    // bit manipulation
    bool checkInclusion(string s1, string s2) {
        
        int m = s1.size() , n = s2.size();
        
        if(m > n)return false;
        
       unordered_map<char,int> mp;
        
       for(auto &i : s1){
           mp[i]++;
       }
        
       for(int i=0;i<m;i++){
           mp[s2[i]]--;
           if(mp[s2[i]] == 0)mp.erase(s2[i]);
       }
        
       if(mp.empty())return true;
        
       for(int i=m;i<n;i++){
           mp[s2[i]]--;
           
           if(mp[s2[i]] == 0)mp.erase(s2[i]);
           
           mp[s2[i-m]]++;
           
           if(mp[s2[i-m]] == 0)mp.erase(s2[i-m]);
           
           if(mp.empty())return true;
       }
        
      return false;  
    }
};