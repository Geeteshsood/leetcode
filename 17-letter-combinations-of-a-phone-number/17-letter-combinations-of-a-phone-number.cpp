class Solution {
public:
    
    unordered_map<char,string> mp;
    
    vector<string> find(int i,string &s){
        
        if(i == s.size())return {""};
        
        vector<string> ans;
        
        auto res =  find(i+1,s);
      
        string str = mp[s[i]-'0'];
        
        for(auto &it:str){
            for(auto &x:res){
                ans.push_back(it + x);
            }
        }
        
      return ans;  
    }
    
    vector<string> letterCombinations(string s) {
        
        mp[2] = "abc" , mp[3] = "def" , mp[4] = "ghi" , mp[5] = "jkl" , mp[6] = "mno" , mp[7] = "pqrs" ,         mp[8] = "tuv" , mp[9] = "wxyz";
        
        vector<string> res = find(0,s);
        
        if(res[0] == "")return {};
            
     return res;
    }
};