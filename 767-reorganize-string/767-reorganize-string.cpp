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
            pq.push({y,x});
        }
        
        string str;
        
        while(pq.size() > 1){
            
           auto x = pq.top();
           pq.pop();
           auto y = pq.top();
           pq.pop();
           
           str += x.second;
           str += y.second;
              
           if(x.first != 1)pq.push({x.first-1,x.second}); 
           if(y.first != 1)pq.push({y.first-1,y.second});    
            
        }
     
        if(pq.size() == 0){
            return str;
        }
        else if(pq.top().first == 1){
            str += pq.top().second;
            return str;
        }
       
        return "";
    }
};