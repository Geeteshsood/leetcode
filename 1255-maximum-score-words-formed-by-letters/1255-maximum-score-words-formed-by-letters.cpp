class Solution {
public:
    
    unordered_map<int,int> dp[15];
    
    bool isValid(int i,unordered_map<int,int> &mp){
        
          for(auto [x,y] : dp[i]){
              if(mp[x] < y){
                  return false;
              }
          }
        
        return true;
    }
    
    int find(int i,int n,vector<int> &score,unordered_map<int,int> &mp){
        
        if(i == n)return 0;
        
         int x  = 0 , y = 0;
        
         if(isValid(i,mp)){
             for(auto [x,y] : dp[i]){
               if(mp[x] == y)mp.erase(x);
               else mp[x]-= y;
             }
             
             x = score[i] + find(i+1,n,score,mp);
             
             for(auto [x,y] : dp[i]){
                  mp[x]+=y;
             }
         }
         y = find(i+1,n,score,mp);
        
        
     return max(x,y); 
    }
    
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& v) {
        
        int n = words.size();
        
        vector<int> score(n);
        
        for(int i=0;i<n;i++){
            int sum = 0;
            for(auto &x : words[i]){
                sum += v[x-'a'];
                dp[i][x]++;
            }
            score[i] = sum;
        }
        // for(int i=0;i<n;i++){
        //     cout<<score[i]<<" ";
        // }
        unordered_map<int,int> mp;
        
        for(auto &x : letters){
            mp[x]++;
        }
        
        return find(0,n,score,mp);
        
    }
};