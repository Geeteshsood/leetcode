class Solution {
public:
    string reorganizeString(string s) {
        
        int n = s.size();
        
        unordered_map<char,int> mp;
        
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        
        priority_queue<pair<int,char>> pq;
        
        for(auto &[x,y] : mp){
            if(y > (n+1)/2)return "";
            pq.push({y,x});
        }
        
        string str(s);
        
        int idx = 0;
        while(pq.size()){
        
          int freq = pq.top().first;
          char ch  = pq.top().second;
            
          for(int i=0;i<freq;i++){
              str[idx] = ch;
              idx+=2;
              if(idx > n-1)idx = 1;
          }
         
          pq.pop();
        }
       
        return str;
    }
};