class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        
        int n = arr.size() , sum = 0 , mod = 1e9 + 7;
        
        for(int i=0;i<n;i++){
            sum = sum + arr[i];
        }
        
        int ans = INT_MIN , val = 0;
        
        for(int i=0;i<min(2,k)*n;i++){
            val = max(0,val + arr[i%n]);
            ans = max(ans,val);
        }
        
        if(sum > 0 && k>2){
            for(int i=0;i<k-2;i++){
                ans = (ans + sum)%mod;
            }
        }
        
      return ans%mod;
    }
};