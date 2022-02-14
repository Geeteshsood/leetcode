class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        
        int n = nums.size();
        int s = 0 , e = n-1;
        
        vector<int> v(n);
        
        for(int i=0;i<n;i++){
            if(nums[i] < pivot){
              v[s] = nums[i];
              s++;
            }
        }
        
        for(int i=n-1;i>=0;i--){
            if(nums[i] > pivot){
              v[e] = nums[i];
              e--;
            }
        }

        for(int i=s;i<=e;i++){
            v[i] = pivot;
        }
        
        return v;
    }
};