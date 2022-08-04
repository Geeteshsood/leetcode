class Solution {
public:
    
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
       
         int n = nums.size();
         vector<int> res;
         vector<vector<int>> prefix(n,vector<int>(101));
        
         for(int i=0;i<n;i++){
             for(int num=1;num<=100;num++){
                 if(i > 0 )prefix[i][num] = prefix[i-1][num];
             }
             prefix[i][nums[i]]++;
         }
        
        for(auto &it : queries){
            
            int u = it[0] , v = it[1] , ans = INT_MAX , pre = -1;
            
            for(int num=1;num<=100;num++){
                
                int freq = 0;
                
                if(u != 0)freq = prefix[v][num] - prefix[u-1][num];
                else freq = prefix[v][num];
                
                if(freq > 0){
                    // cout<<u<<" "<<v<<" -> "<<num<<endl;
                    if(pre == -1){
                        pre = num;
                    }
                    else{
                        ans = min(ans,abs(num-pre));
                        pre = num;
                    }
                } 
            }
            if(ans == INT_MAX)ans = -1;
            res.push_back(ans);
        }
        
        return res;
    }
};