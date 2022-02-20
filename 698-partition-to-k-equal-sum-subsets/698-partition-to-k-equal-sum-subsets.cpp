class Solution {
public:
    
    vector<int> res;
    
    void find(int i,int sum,vector<int> &nums,int mask,int val){
      
        int n = nums.size();
        
        if(i == n){
            if(sum == val)res.push_back(mask);
            return ;
        }
        
        find(i+1,sum + nums[i],nums,mask|(1<<i),val);
        find(i+1,sum,nums,mask,val);
    }
    
    bool check(int i,int mask,int cnt,int k,int &target){
        
        int n = res.size();
        
        if(cnt == k){
            return mask == target;
        }
        if(i == n || cnt > k)return false;
            
        bool flag = false;
        
        if(!(mask & res[i])){
            flag = check(i+1,mask^res[i],cnt+1,k,target);
        }
        return flag || check(i+1,mask,cnt,k,target);
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        int sum = accumulate(nums.begin(),nums.end(),0);
        
        if(sum%k != 0)return false;
        
        int val = sum/k;
        
        find(0,0,nums,0,val);
        
        int target = (1<<n)-1;
        
        if(res.size() >= k)return check(0,0,0,k,target);
    
       return false; 
    }
};