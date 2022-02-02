class Solution {
public:
    int countTriplets(vector<int>& arr) {

        int n = arr.size(),ans = 0 ,Xor =0;
        
        unordered_map<int,int> cnt,total;
        
        cnt[Xor]++ , total[Xor] = -1;
        
        for(int i=0;i<n;i++){
            Xor = Xor^arr[i];
            if(cnt.count(Xor)){
               ans += (i-1)*cnt[Xor] - total[Xor];
            }
            
            cnt[Xor]++;
            total[Xor] += i;
        }
    
        return ans; 
    }
    
};