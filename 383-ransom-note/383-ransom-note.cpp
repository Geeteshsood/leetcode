class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        vector<int> dest(26),src(26);
        
        for(auto &ch : ransomNote){
              dest[ch-'a']++;
        }
        for(auto &ch : magazine){
              src[ch-'a']++;
        }
        
        for(int i=0;i<26;i++){
            if(dest[i] > src[i])return false;
        }
        
      return true;  
    }
};