class Solution {
public:
    int compareVersion(string s1, string s2) {
        
        int m = s1.size() , n = s2.size();
        
        vector<int> dp1,dp2;
        
        for(int i=0;i<m;i++){
            
            int mask = 0;
            bool flag = true;
            
            while(i < m && s1[i]!='.'){
               if(s1[i] == '0' && flag){
                   i++;
                   continue;
               }
               else flag = false;
                
               mask=mask*10 + (s1[i]-'0'); 
               i++;
            }
            
            dp1.push_back(mask);
        }
        
       for(int i=0;i<n;i++){
            
            int mask = 0;
            bool flag = true;
           
            while(i < n && s2[i]!='.'){
               if(s2[i] == '0' && flag){
                   i++;
                   continue;
               }
               else flag = false;
                
               mask=mask*10 + (s2[i]-'0'); 
               i++;
            }
            
            dp2.push_back(mask);
        }
        
        // for(auto &i: dp1)cout<<i<<" ";
        // cout<<endl;
        // for(auto &i: dp2)cout<<i<<" ";
        // cout<<endl;
        
        int i=0,j=0;
        for(;i<min(dp1.size(),dp2.size());i++,j++){
            if(dp1[i] != dp2[j]){
                if(dp1[i] < dp2[j])return -1;
                else return 1;
            }
        }

        for(int x=i;x<dp1.size();x++){
            if(dp1[x] != 0)return 1;
        }
        for(int x=j;x<dp2.size();x++){
            if(dp2[x] != 0)return -1;
        }
       
        return 0;
    }
};