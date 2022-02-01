class Solution {
public:
    
    vector<int> ans;
    unordered_map<string,bool> vis;
    
    bool find(string s,int cnt,int val,int one){
        
        // cout<<s<<" "<<one<<endl;
        int n = s.size();
        if(cnt == (1<<n)){
            
            if(one == 1){
                return true;
            }
            
            return false;
        }
        
        vis[s] = true;
        
        for(int i=0;i<n;i++){
            // cout<<s<<endl;
            if(s[i] == '1')s[i] = '0',one--;
            else s[i] = '1',one++;
            
            int x = val;
            // cout<<s<<"*"<<endl;
            if(s[i] == '0')val -= 1<<(n-i-1);
            else val += 1<<(n-i-1);
            
            if(!vis[s] && find(s,cnt+1,val,one)){
                
                ans.push_back(val);
                return true;
            }
            
            val = x;
            if(s[i] == '1')s[i] = '0',one--;
            else s[i] = '1',one++;
        }
        
        vis[s] = false;
        
        return false;
    }
    
    vector<int> grayCode(int n) {
        
         string s;
        
         for(int i=0;i<n;i++){
             s+='0';
         }
        
         find(s,1,0,0);
         ans.push_back(0);
        
        reverse(ans.begin(),ans.end());
        
        return ans;
        
    }
};