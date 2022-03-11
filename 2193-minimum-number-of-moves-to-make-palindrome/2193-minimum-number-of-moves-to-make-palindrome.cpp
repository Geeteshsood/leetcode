class Solution {
public:
    
    int find(string s){
        
        int n = s.size();
        
        if(n == 0){
            return 0;
        }
          
        if(s[0] == s[n-1]){
            return find(s.substr(1,n-2));
        }
        else{
            
            vector<int> v(26,-1);
            
            for(int i=0;i<n;i++){
                if(v[s[i]-'a']==-1)v[s[i]-'a']=i;
            }
            
            int st = -1 , mini = INT_MAX;
            
            for(int i=n-1;i>=0;i--){
                if(i != v[s[i]-'a']){
                    int moves = n-i-1 + v[s[i]-'a'];
                    if(moves < mini){
                        mini = moves;
                        st= i;
                    }
                }
            }
            
             int f = v[s[st]-'a'];
             string p;
            
             if(f>0)p+=s.substr(0,f);
             if(st-f>0)p+=s.substr(f+1,st-f-1);
             if(st+1<n)p+=s.substr(st+1);
            
             return mini + find(p);
            
        }
    }
    
    int minMovesToMakePalindrome(string s) {
        
        int n = s.size();
        return find(s);
        
    }
};