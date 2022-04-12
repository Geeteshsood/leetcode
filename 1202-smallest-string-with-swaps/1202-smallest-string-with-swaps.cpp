class Solution {
public:
    
    int find(int x,vector<int> &par){
        
        if(x == par[x])return x;
        
        return par[x] = find(par[x],par);
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
         int n = s.size();
        
         vector<int> par(n);
        
         for(int i=0;i<n;i++){
             par[i] = i;
         }
        
         for(auto &it : pairs){
             
              int lx = find(it[0], par);
              int ly = find(it[1], par);
             
              if(lx != ly){
                  par[lx] = ly;
              }
         }
        
         unordered_map<int,vector<int>> mp;
        
         for(int i=0;i<n;i++){
             par[i] = find(i,par);
             mp[par[i]].push_back(i);
         }
         
         for(auto &it : mp){
             
             string str;
             
             for(auto &x : it.second){
                 str += s[x];
             }
             
             sort(str.begin(),str.end());
             
             int j = 0;
             
             for(auto &x : it.second){
                 s[x] = str[j];
                 j++;
             }
             
         }
         
       return s;
    }
};