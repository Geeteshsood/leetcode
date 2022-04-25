class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int n = s.size() , maxi = INT_MIN , j = 0;
        
        unordered_map<int,int> freq;
        
        for(int i=0;i<n;i++){
            
            freq[s[i]]++;
            
            if(freq[s[i]] > maxi){
                maxi = freq[s[i]];
            }
            
            int val = i-j+1-maxi;
            
            if(val > k){
                freq[s[j]]--;
                j++;
            }
        }
        
       return n-j; 
    }
};