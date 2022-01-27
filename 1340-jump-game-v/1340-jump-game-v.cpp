class Solution {
public:
    
    int find(int i,int d,vector<int> &arr,vector<int> &dp){
        
        int n = arr.size();
        
        if(i < 0 || i >= n)return INT_MIN;
        
        if(dp[i] != -1){
            return dp[i];
        }
        
        int x = INT_MIN , y = INT_MIN;
        
        int lim = min(i+d,n-1);
        
        for(int j=i+1;j<=lim;j++){
              if(arr[i] > arr[j]){
                 x = max(x , find(j,d,arr,dp));
              }
              else break;
        }
        
        lim = max(0,i-d);
        
        for(int j=i-1;j>=lim;j--){
              if(arr[i] > arr[j]){
                  y = max(y , find(j,d,arr,dp));
              }
              else break;
        }
        
        x = max(x,0),y = max(y,0);

        return dp[i] = 1 + max(x , y);
    }
    
    int maxJumps(vector<int>& arr, int d) {
        
        int n = arr.size() , ans = INT_MIN;
        
        vector<int> dp(n,-1);
        
        for(int i=0;i<n;i++){
            
            int x = find(i,d,arr,dp);
            ans = max(ans,x);         
        }
        
       return ans; 
    }
};