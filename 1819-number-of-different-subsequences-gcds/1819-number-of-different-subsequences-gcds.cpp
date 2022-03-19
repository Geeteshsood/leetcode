class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        
        int m = *max_element(nums.begin(),nums.end()) + 1;
        
        int n = nums.size() , cnt = 0;
        
        vector<int> valid(m,false);
        
        for(int i=0;i<n;i++){
            valid[nums[i]] = true;
        }
        
        for(int i=1;i<m;i++){
            int gcd1 = 0;
            for(int j=i;j<m;j+=i){
                if(valid[j]){
                   if(gcd1 != 0)gcd1 = __gcd(gcd1,j);
                   else gcd1 = j;
                }
            }
            
            if(gcd1 == i){
                valid[i] = true;
                cnt++;
            }
        }
     
        return cnt;
    }
};