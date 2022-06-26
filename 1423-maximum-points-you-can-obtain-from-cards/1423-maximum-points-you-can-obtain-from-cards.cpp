class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        
        int n = cp.size();
        vector<int> left(n);
        
        for(int i=0;i<n;i++){
            if(i == 0)left[i] = cp[i];
            else left[i] = left[i-1] + cp[i];
        }

        int sum = 0;
        
        for(int i=0;i<k;i++){
            int front = left[i];
            int back = left[n-1] - left[n-k+i];
            sum = max(sum,front + back);
        }
        
         int end = 0;
        
         if(k != n)end = left[n-1] - left[n-k-1];
        
        return max(end,sum);
    }
};