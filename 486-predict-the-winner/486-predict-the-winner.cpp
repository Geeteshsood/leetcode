class Solution {
public:
    
    pair<int,int> find(int i,int j,vector<int> &nums,bool flag){
        
        if(i == j){
            if(flag)return {nums[i],0};
            else return {0,nums[j]};
        }
        
        if(flag){ 
            auto[fp1,sp1] = find(i+1,j,nums,false);
            auto[fp2,sp2] = find(i,j-1,nums,false);
            
            fp1 += nums[i] , fp2 += nums[j];
            
            if(fp1 > fp2)return {fp1,sp1};
            else return {fp2,sp2};
        }
        else{
            
            auto[fp1,sp1] = find(i+1,j,nums,true);
            auto[fp2,sp2] = find(i,j-1,nums,true);
            
            sp1 += nums[i] , sp2 += nums[j];
            
            if(sp1 > sp2)return {fp1,sp1};
            else return {fp2,sp2};
        }
     
     return {-1,-1};
    }
    
    
    bool PredictTheWinner(vector<int>& nums) {
        
        int n = nums.size();
        
        auto [fp,sp] = find(0,n-1,nums,true);
        
      return fp>=sp;  
    }
};