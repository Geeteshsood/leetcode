class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        vector<int> freq(26);
        
        for(auto &ch : ransomNote){
              freq[ch-'a']++;
        }
        for(auto &ch : magazine){
              freq[ch-'a']--;
        }
        
        for(int i=0;i<26;i++){
            if(freq[i] > 0)return false;
        }
        
      return true;  
    }
};