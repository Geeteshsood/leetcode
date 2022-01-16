class Solution {
public:
    
    int find(int i,int j,vector<int> &nums){

        if(i == j)return nums[i];
        else if(i > j)return 0;
        
        int x = nums[i] + min(find(i+2,j,nums),find(i+1,j-1,nums));
        int y = nums[j] + min(find(i+1,j-1,nums),find(i,j-2,nums));
        
        return max(x,y);
    }
    
    bool PredictTheWinner(vector<int>& nums){
        
       int n = nums.size() , total = 0;
       for(int i=0;i<n;i++)total += nums[i];
        
       int fp = find(0,n-1,nums);
       int sp = total - fp;
        
     return fp>=sp;
    }
};