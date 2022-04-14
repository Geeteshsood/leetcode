class Solution {
public:
    
       int mem[1<<14];
    
    int find(int i,vector<int> &nums1,vector<int> &nums2,int mask){
        
        int m = nums1.size();
        
        if(i == m)return 0;
        
        if(mem[mask] != -1){
            return mem[mask];
        }
        
        int val = INT_MAX;
        
        for(int j=0;j<m;j++){
            
            if(!(mask & (1<<j))){
                mask = mask | (1<<j);
                val = min(val ,  (nums1[i]^nums2[j]) + find(i+1,nums1,nums2,mask));
                mask = mask ^ (1<<j);
            }
            
        }
        
     return mem[mask] = val; 
        
    }
    
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        
        memset(mem,-1,sizeof(mem));
        
        int mask = 0;
        
        return find(0,nums1,nums2,mask);
     
    }
};