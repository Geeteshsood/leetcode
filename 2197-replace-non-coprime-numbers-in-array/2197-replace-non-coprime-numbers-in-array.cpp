class Solution {
public:
    
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        
        vector<int> st;
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            
            int cur = nums[i];
            
            while(st.size()){
                
               int gcd1 = __gcd(cur,st.back());
                
               if(gcd1 > 1){
                   int lcm = (cur/gcd1)*st.back();
                   st.pop_back();
                   cur = lcm;
               }
               else break;
            }
            
            st.push_back(cur);
        }
        
        return st;
    }
};