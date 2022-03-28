class Solution {
public:
    int minDeletion(vector<int>& nums) {
        
        int n = nums.size() , len =  1 , remove = 0 , odd = 0;
        bool flag = true;
        
        nums.push_back(-1);
        
        for(int i=0;i<n;i++){
            
            if(nums[i] == nums[i+1]){
                  if(flag){
                      odd = i%2;
                      flag = false;
                  }
                  len++;
            }
            else{
                if(len > 1){
                   if(remove%2)odd = !odd;
                   
                   if(odd){
                       remove += len-2;
                   }
                   else remove += len-1;
                 
                }
                
                 len = 1;
                 flag = true;
            }
        }
        
        int finalLen = n - remove;
        
        if(finalLen%2)remove++;
        
      return remove;  
    }
};