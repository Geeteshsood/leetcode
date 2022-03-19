class Solution {
public:

    vector<int> v;
    int ans = 0;
    
    int calculate(vector<int> v){
        
        sort(v.begin(),v.end());
        
        int sum = 0;
        
        for(int i=0;i<v.size();i++){
             sum += (i+1)*v[i];
        }
        
        return sum;
    }
    
    void find(int i,vector<int> &nums){
        
        int n = nums.size();
        while(i<n && nums[i] == -1)i++;
        
        if(i == n){
            
            ans = max(ans,calculate(v));
            return ;
            
        }
        
        int val = INT_MIN;
        
        for(int j=i+1;j<n;j++){
            
            if(nums[j] == -1)continue;
            
            int score = __gcd(nums[i],nums[j]);
            
            int num = nums[j];
            nums[j] = -1;
            
            v.push_back(score);
            find(i+1,nums);
            v.pop_back();

            nums[j] = num;
        }
    }
    
    int maxScore(vector<int>& nums) {
        
        int n = nums.size();

        find(0,nums);
        
        return ans;
    }
};