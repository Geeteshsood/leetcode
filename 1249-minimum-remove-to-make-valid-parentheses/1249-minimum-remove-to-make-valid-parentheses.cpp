class Solution {
public:
   string minRemoveToMakeValid(string s) {
        string d="";
        
        int n=s.size();
       for( int i=0;i<n;i++){
           d+=s[i];
       }
        stack<int>a;
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
          d.erase(d.begin()+a.top());
          a.pop();
      }
        return d;
    }
};