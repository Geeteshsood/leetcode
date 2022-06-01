class Solution {
public:

    static bool cmp(vector<int> &a , vector<int> &b){
         return a[0] < b[0];
    }
    
    int search(int i,vector<vector<int>> &res){
        
        int n = res.size();
        int et = res[i][1];
        
        int start = i , end = n-1 , ans = n;
        
        while(start <= end){
            
            int mid = start + (end - start)/2;
            
            int st = res[mid][0];
            
            if(et <= st){
                ans = mid;
                end = mid-1;
            }
            else start = mid+1;
            
        }
        
        return ans;
    }
    
    int find(int i,vector<vector<int>> &res,vector<int> &dp){
        
        int n = res.size();
        
        if(i == n){
            return 0;
        }

        if(dp[i] != -1)return dp[i];

        int et = res[i][1];
          
        int nex = search(i,res);
        
        int x = res[i][2] + find(nex,res,dp);
        
        int y = find(i+1,res,dp);
        
        return dp[i] = max(x,y);
    }
    
    int jobScheduling(vector<int>& st, vector<int>& et, vector<int>& pro) {
        
        int n = st.size();
        vector<vector<int>> res(n,vector<int>(3));
        
        for(int i=0;i<n;i++){
            res[i][0] = st[i];
            res[i][1] = et[i];
            res[i][2] = pro[i];
        }
        
        vector<int> dp(n,-1);
        
        sort(res.begin(),res.end(),cmp);
        
        return find(0,res,dp);
    }
};