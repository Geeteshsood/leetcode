class Solution {
public:
    bool isPowerOfFour(int n) {
        
       if(n <= 0)return 0;
        
       int rsb = n & -n;
        
       if(n != rsb)return 0;
       
       n = n-1;
        
       if(n == 0)return 1;
        
       int start = 0 , end = 31 , ans = 0;
        
       while(start <= end){
            int mid = start + (end - start)/2;
           
            if(n & (1 << mid)){
                // cout<<mid<<endl;
                ans = mid;
                start = mid + 1;
            }
            else end = mid-1;
       }
      
      return (ans%2 != 0);
        
    }
};