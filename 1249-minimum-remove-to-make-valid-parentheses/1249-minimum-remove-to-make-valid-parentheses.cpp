class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        int n=s.size();

        stack<int> a;
      unordered_map<char,char>m;
        m['(']=')';
        
        for(int i=0;i<n;i++){
            char c=s[i];
            if(c=='(')a.push(i);
            else if(c==')'){
                if(a.size()>0 && m[s[a.top()]]==c)a.pop();
                else a.push(i);
            }
        }
        
        if(a.empty())return s;
        
      while(!a.empty()){
          int x = a.top();
          s[x] = ' ';
          a.pop();
      }
        
      s.erase(remove(s.begin(),s.end(),' '),s.end()); 
        
    return s;
    }
};