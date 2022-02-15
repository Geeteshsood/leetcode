class Solution {
public:
    int longestAwesome(string s) {
        
        int n = s.size() , len = 0 , mask = 0;
        unordered_map<int,int> mp;
        mp[0] = -1;
        
        for(int i=0;i<n;i++){
            
           mask = mask^(1<<(s[i]-'0'));
            
           if(mp.find(mask) != mp.end()){
                 // cout<<i<<endl;
                 len = max(len,i-mp[mask]);
           }
           else{
               mp[mask] = i;
           }
            
//            bitset<10> b(mask);
//             cout<<i<<" -> "<<b<<endl;
            
           for(int j=0;j<10;j++){
               
              int tmask = mask^(1<<j);
               
              if(mp.find(tmask) != mp.end()){
                 len = max(len,i-mp[tmask]);
              }
           }
        }
        
      return len;
    }
};