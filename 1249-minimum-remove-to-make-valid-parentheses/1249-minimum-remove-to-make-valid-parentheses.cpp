class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
         int n=s.length();
         vector<pair<char,int>> res;   
         for(int i=0;i<n;i++){
                 
           if(s[i]=='(')res.push_back({s[i],i});
           else if(s[i]==')'){   
                if(res.empty() || res.back().first==')')res.push_back({s[i],i});
                else res.pop_back();
           }
         } 
       for(int i=n-1;i>=0;i--){
           if(!res.empty() && i==res.back().second){
                  s[i]=' ';
                  res.pop_back();
           } 
       }  
       
       s.erase(remove(s.begin(),s.end(),' '),s.end());     
            
return s;            
    }
};