class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        
        int n = arr.size();
        
        for(int i=0;i<n;i++){
            if(arr[i] != 0)continue;
            
            int prev = 0 , cur = 0;
            
            for(int j=i+1;j<n;j++){
                cur = arr[j];
                arr[j] = prev;
                prev = cur;
            }
            i++;
        }
        
    }
};