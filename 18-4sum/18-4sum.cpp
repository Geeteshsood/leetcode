class Solution {
public:
    typedef long long ll;
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
             vector<vector<int>>ans;
        if(nums.size()==0)return ans;
        
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                
                ll a= (ll)target - (ll)(nums[i] + nums[j]);
                
                int front=j+1;
                int last=n-1;
                while(front<last){
                    
                    ll sum=nums[front]+nums[last];
                    
                    if(sum<a){
                        front++;
                    }
                   else if(sum>a){
                        last--;
                    }
                    else{
                           vector<int>v(4,0);
                       v[0]=nums[i]; 
                          v[1]=nums[j];  
                           v[2]=nums[front]; 
                           v[3]=nums[last]; 
                        ans.push_back(v);
                        
                        while(front<last && nums[front]==v[2])++front;
                         while(front<last && nums[last]==v[3])--last;
                    }
                }
            
                 while(j+1<n && nums[j+1]==nums[j])++j;
                    
            }
               while(i+1<n && nums[i+1]==nums[i])++i;
                     
        }
        return ans;
    
    }
};