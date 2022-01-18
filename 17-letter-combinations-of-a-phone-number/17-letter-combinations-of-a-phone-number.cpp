class Solution {
public:
    
    vector<string> letterCombinations(string s) {
        
      if(s.size() == 0)return {};
        
      unordered_map<int,string> mp;
        
      mp[2] = "abc" , mp[3] = "def" , mp[4] = "ghi" , mp[5] = "jkl" , mp[6] = "mno" , mp[7] = "pqrs" ,         mp[8] = "tuv" , mp[9] = "wxyz";
        
      int n = s.size();
      vector<string> cur{{""}};
        
      for(int i=n-1;i>=0;i--){
          vector<string> nex;
          for(auto &x :mp[s[i]-'0']){
              for(auto &i :cur){
               nex.push_back(x + i);
              }    
          }
          cur = nex;
      }
        
     return cur;
    }
};