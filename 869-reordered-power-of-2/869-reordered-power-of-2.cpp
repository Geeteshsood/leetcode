class Solution {
public:
    
    void count(int n,vector<int> &arr){
        
        while(n){
            arr[n%10]++;
            n = n/10;
        }
        
    }
    
    bool reorderedPowerOf2(int n) {
        
        vector<int> arr(10);
        count(n,arr);
        
        for(int bit=0;bit<31;bit++){
            
            vector<int> arr2(10);
            
            count(1<<bit,arr2);
            
            bool flag = true;
            
            for(int i=0;i<10;i++){
                if(arr[i] != arr2[i]){
                    flag = false;
                    break;
                }
            }
            
            if(flag)return true;
            
        }
        
        return false;
    }
};