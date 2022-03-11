class Solution {
public:
    
    unordered_map<string,int> dp;
    
    int find(string s){
        
        int n = s.size();
        if(n == 0){
            return 0;
        }
          
        if(dp.count(s))return dp[s];
        
        if(s[0] == s[n-1]){
            return  dp[s] = find(s.substr(1,n-2));
        }
        else{
            
            string s1,s2;
            int x = INT_MAX,y = INT_MAX,z = INT_MAX;
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
            
             z = mini + find(p);
            
            return dp[s] = z;
        }
    }
    
    int minMovesToMakePalindrome(string s) {
        
        int n = s.size();
        return find(s);
        
    }
};