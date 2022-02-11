class Solution {
public:
    
    bool checkInclusion(string s1, string s2) {
        
        int m = s1.size() , n = s2.size();
        
        if(m > n)return false;
        
        vector<int> v1(26),v2(26);
        
        for(auto &i : s1){
            v1[i-'a']++;
        }
         
        for(int i=0;i<m;i++){
            v2[s2[i]-'a']++;
        }
        
        if(v1 == v2)return true;
        
       for(int i=m;i<n;i++){
           v2[s2[i]-'a']++;
           
           v2[s2[i-m]-'a']--;
           
           if(v1 == v2)return true;
       }
        
      return false;  
    }
};