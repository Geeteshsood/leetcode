class Solution {
public:
    
    int getbitmask(string &s){
        
       int mask = 0;
        
       for(auto &ch : s){
          int bit = ch - 'a';          
          mask = mask | (1<<bit);
       }
            
      return mask;
    }
    
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        
        vector<int> ans;
        
        int m = words.size() , n = puzzles.size();
        
        unordered_map<int,int> mp;
        
        for(auto &word : words){
            
           int wmask = getbitmask(word);
           
           mp[wmask]++;
        }
        
        for(auto &puzzle : puzzles){
            
            int pmask = getbitmask(puzzle);
            
            int bit = puzzle[0]-'a';
            int cnt = 0;
            
            for(auto &[wmask,freq] : mp){
               
                bool flag1 = (wmask == (pmask & wmask));
                bool flag2 = (wmask & (1<<bit));
                 
                if(flag1 && flag2){
                    cnt += freq;
                }
            }
            
            ans.push_back(cnt);
        }
      
        return ans;
    }
};