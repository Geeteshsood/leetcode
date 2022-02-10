class Solution {
public:
    
   static bool cmp(string &a , string &b){
       return a.size()<b.size();
   }
    
   vector<int> par;
    
   int find(int x,vector<int> &par){
      
       if(x == par[x])return x;
       
       return par[x] = find(par[x],par);
   }
    
   void connect(int i,int j){
       
        int lx = find(i,par);
        int ly = find(j,par);
       
        if(lx != ly){
            par[lx] = ly;
        }
   }
    
   int getbitmask(string &s){
       
       int mask = 0;
       
       for(auto &ch : s){
           mask = mask | (1<<(ch - 'a'));
       }

       return mask;
   }
    
    vector<int> groupStrings(vector<string>& words) {
        
        int n = words.size();
        par = vector<int> (n);
        
        for(int i=0;i<n;i++){
            par[i] = i;
        }
        
        unordered_map<int,int> mp;
        
        for(int i=0;i<n;i++){
            
            int xmask = getbitmask(words[i]);

            for(int j=0;j<26;j++){
                
                   bool set = xmask & (1 << j);
                
                if(set){
                   int mask = xmask ^ (1 << j) ; // unset bit
                
                   if(mp.count(mask)){
                       connect(i,mp[mask]);
                   }                                 // checking for deletion
                    
                   for(int k=0;k<26;k++){
                       
                       if(mask & (1<<k))continue;
                       
                       int rmask = mask | (1 << k);    // replacing bit

                       if(mp.count(rmask)){
                           connect(i,mp[rmask]);
                       }                              // checking for replacing 
                   }
                }
                else{
                       
                   int amask = xmask | (1 << j);    // adding bit
                    
                   if(mp.count(amask)){
                       connect(i,mp[amask]);
                   }                              // checking for addition
                }
              }
               
          mp[xmask] = i;
        }
        
        unordered_map<int,int> dp;
        
        for(int i=0;i<n;i++){
            par[i] = find(i,par);
        }
        
        for(int i=0;i<n;i++){
            dp[par[i]]++;
        }
        
        int largest = INT_MIN;
        
        for(auto &[x,y] : dp){
            largest = max(largest,y);
        }
        
        int size = dp.size();
        
        return {size,largest};
    }
};