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
        
         for(int i=0;i<n;i++){
             par[i] = find(i,par);
         }
         
         unordered_map<int,string> mp;
         unordered_map<int,int> freq;
        
         for(int i=0;i<n;i++){
             // cout<<i<<" "<<par[i]<<endl;
             mp[par[i]]+=s[i];
         }
        
         for(auto &[x,y] : mp){
             sort(mp[x].begin(),mp[x].end());
             freq[x] = 0;
         }
        
         string str;
        
         for(int i=0;i<n;i++){
            str += mp[par[i]][freq[par[i]]];
            freq[par[i]]++;
         }
         
       return str;
        
        
    }
};