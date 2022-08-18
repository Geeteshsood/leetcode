class Solution {
public:
    
    int count(int mid,vector<int> &nums,vector<int> &prefix){
        
        int n = nums.size(),cnt = 0,y=-1;
        
        for(int i=0;i<n;i++){
            
            int high = nums[i] + mid;
            
            if(high > nums[n-1]){
                y = n;
            }
            else y = prefix[high];
            
            cnt += (y-i-1);
            
        }
        
      return cnt;  
    }
    
    int smallestDistancePair(vector<int>& nums, int k) {
        
        int n = nums.size();
        sort(nums.begin(),nums.end());

        vector<int> prefix(nums[n-1]+1);

        int i = 0;
        
        for(int val=nums[0];val<=nums[n-1];val++){
            int cnt = 0;
            if(i == n || val != nums[i]){
                if(val == 0)prefix[val] = 0;
                else prefix[val] = prefix[val-1];
            }
            else{
                while(i < n && nums[i]==val){
                    cnt++;
                    i++;
                }
                if(val == 0)prefix[val] = cnt;
                else prefix[val] = prefix[val-1] + cnt;
            }
        }
        
        int start = 0;
        int end = nums[n-1]-nums[0];
        int ans = -1;
        
        while(start <= end){
            
           int mid = start + (end - start)/2;
            
           if(count(mid,nums,prefix) >= k){
               ans = mid;
               end = mid-1;
           }
           else start = mid+1;
            
        }
        
        return ans;
    }
};