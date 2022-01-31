class Solution {
public:
    vector<vector<int>> subsets(vector<int>& arr) {
        
         vector<vector<int>> ans;
        
         int n = arr.size();
    
         for(int num=0;num<(1<<n);num++){
             
             vector<int> v;
             int val = num;
             
             for(int i=0;i<n;i++){
                 if(val & 1){
                     v.push_back(arr[i]);
                 }
                 
                 val = val >> 1;
             }
             
             ans.push_back(v);
         }
    
        return ans;
    }
};