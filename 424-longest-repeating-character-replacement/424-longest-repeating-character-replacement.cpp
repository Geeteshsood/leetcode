class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int n = s.size() , len = INT_MIN , maxi = INT_MIN , j = 0;
        
        unordered_map<char,int> freq;
        
        for(int i=0;i<n;i++){
            
            freq[s[i]]++;
            
            if(freq[s[i]] > maxi){
                maxi = freq[s[i]];
            }
            
            int val = i-j+1-maxi;
            
            if(val <= k){
                len = max(len,i-j+1);
            }
            else{
                freq[s[j]]--;
                j++;
            }
        }
        
       return len; 
    }
};