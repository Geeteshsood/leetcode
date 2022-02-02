class Solution {
public:
    int countTriplets(vector<int>& arr) {

        int n = arr.size(),cnt = 0;
        
        for(int i=0;i<n;i++){
            int Xor = 0;
            for(int j=i;j<n;j++){
                Xor = Xor^arr[j];
                if(Xor == 0){
                    cnt += j-i;
                }
            }
        }
    
        return cnt; 
    }
    
};