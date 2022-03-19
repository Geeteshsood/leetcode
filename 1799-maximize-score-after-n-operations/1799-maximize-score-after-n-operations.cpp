class Solution {
public:

    vector<int> v;
    int ans = 0;
    
    void find(int i,vector<int> &nums){
        
        int n = nums.size();
        while(i<n && nums[i] == -1)i++;
        
        if(i == n){
            
            vector<int> res(v);
            
            sort(res.begin(),res.end());
            int sum = 0;
            
            for(int i=0;i<res.size();i++){
                 sum += (i+1)*res[i];
            }
            
            ans = max(ans,sum);
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