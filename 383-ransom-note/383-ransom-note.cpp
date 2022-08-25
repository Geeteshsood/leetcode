class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        vector<int> vis(26);
        
        for(int i=0;i<magazine.size();i++){
            vis[magazine[i]-'a']++;
        }
        
        for(int i=0;i<ransomNote.size();i++){
            vis[ransomNote[i]-'a']--;
            
            if(vis[ransomNote[i]-'a'] < 0)return false;
        }
        
        return true;
    }
};