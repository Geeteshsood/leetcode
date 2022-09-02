class Solution {
public:
    
    int maxSum(vector<int>& nums,int k) {
        
        set<int> s;
        s.insert(0);
        
        int sum = 0 , ans = INT_MIN;
        int n = nums.size();
        
        for(auto &val : nums){
            
           sum += val;
            
           auto it = s.lower_bound(sum - k);
            
           if(it != s.end()){
               if(sum - *it <= k){
                   ans = max(ans,sum-*it);
               }
           }
            
           s.insert(sum);
        }
        
        return ans;
    }
    
    int find1(vector<vector<int>>& matrix, int k){
        
         int m = matrix.size() , n = matrix[0].size();

        int ans = INT_MIN;
        
        for(int row=0;row<m;row++){
          
           vector<int> sums(n);
            
            for(int i=row;i<m;i++){
                
                int val = 0 , maxi = INT_MIN;
                
                for(int col=0;col<n;col++){
                    
                    sums[col] += matrix[i][col];
                    
                    val = max(val + sums[col],sums[col]);
                    maxi = max(maxi,val);
                    
                }
                
                if(maxi <= k){
                    ans = max(ans,maxi);
                    continue;
                }
                
                int x = maxSum(sums,k);
                
                ans = max(ans,x);
               
            }
        }
        return ans;
    }
    
    int find2(vector<vector<int>> &matrix,int k){
        
        int m = matrix.size() , n = matrix[0].size();

        int ans = INT_MIN;
        
        for(int col=0;col<n;col++){
          
           vector<int> sums(m);
            
            for(int j=col;j<n;j++){
                
                int val = 0 , maxi = INT_MIN;
                
                for(int row=0;row<m;row++){
                    
                    sums[row] += matrix[row][j];
                    
                    val = max(val + sums[row],sums[row]);
                    maxi = max(maxi,val);
                    
                }
                
                if(maxi <= k){
                    ans = max(ans,maxi);
                    continue;
                }
                
                int x = maxSum(sums,k);
                
                ans = max(ans,x);
               
            }
        }
        return ans;
        
    }
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        
        int m = matrix.size() , n = matrix[0].size();
        
        if(n > m){
            return find1(matrix,k);
        }
        
        return find2(matrix,k);
    }
    
};