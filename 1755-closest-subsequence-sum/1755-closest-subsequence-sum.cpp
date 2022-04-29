class Solution {
public:
    
    void find(int i,int lim,int sum,vector<int> &nums,vector<int> &dp){
        
        if(i == lim){
            dp.push_back(sum);
            return ;
        }
        
        find(i+1,lim,sum + nums[i],nums,dp);
        find(i+1,lim,sum,nums,dp);
    }
    
    int minAbsDifference(vector<int>& nums, int goal) {
        
         int n = nums.size() , ans = INT_MAX;
         vector<int> dp1,dp2;
        
         find(0,n/2,0,nums,dp1);
         find(n/2,n,0,nums,dp2);
        
         sort(dp2.begin(),dp2.end());
        
//          for(auto &i : dp1)cout<<i<<" ";
//          cout<<endl;
        
//          for(auto &i : dp2)cout<<i<<" ";
//          cout<<endl;
         
//          cout<<" ** "<<endl;
         for(auto &i : dp1){
             
             int start = 0 , end = dp2.size()-1 , idx = dp2.size()-1;
             // cout<<i<<" ";
             while(start <= end){
                 
                 int mid = start + (end - start)/2;
                 
                 if(i + dp2[mid] >= goal){
                     idx = mid;
                     end = mid-1;
                 }
                 else start = mid + 1;
             }
             // cout<<idx<<endl;
             if(idx > 0)ans = min(ans,abs(goal-(i + dp2[idx-1])) );
             ans = min(ans,abs(goal - (i + dp2[idx])));
         }
        
        return ans;
         
    }
};