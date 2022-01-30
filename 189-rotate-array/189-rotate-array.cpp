class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> v;
        
        k = k%n;
        
        ::rotate(nums.begin(),nums.begin() + n-k , nums.end());
        
    }
};