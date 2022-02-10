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
       
        // cout<<i<<" "<<j<<endl;
       
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
       
      // bitset<26> bx(mask);
      //        cout<<bx<<endl;
      //  cout<<s<<" "<<bx<<endl;
       return mask;
   }
    
    vector<int> groupStrings(vector<string>& words) {
        
        sort(words.begin(),words.end(),cmp);
        
        int n = words.size();
        par = vector<int> (n);
        
        for(int i=0;i<n;i++){
            par[i] = i;
        }
        
        unordered_map<int,int> mp;
        
        for(int i=0;i<n;i++){
            
            int xmask = getbitmask(words[i]);
            
             // bitset<26> bx(xmask);
             // cout<<bx<<endl;
            
            for(int j=0;j<26;j++){
                
                   bool set = xmask & (1 << j);
                
                   if(!set)continue;
              
                
                   int mask = xmask ^ (1 << j) ; // unset bit
                
//                    bitset<26> bm(mask);
//                    cout<<bm<<endl;
                
                   if(mp.count(mask)){
                       connect(i,mp[mask]);
                   }                                 // checking for deletion
                    
                   for(int k=0;k<26;k++){
                       
                       if(mask & (1<<k))continue;
                       
                       int rmask = mask | (1 << k);    // replacing bit
                       
                       // bitset<26> br(rmask);
                       // cout<<br<<endl;
                       
                       if(mp.count(rmask)){
                           connect(i,mp[rmask]);
                       }                              // checking for replacing 
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