class Solution {
public:
    
    typedef long long ll;
    
    long long maximumSubsequenceCount(string text, string p) {
        
        ll seq = 0 , freq1 = 0 , freq2 = 0;
        
        int n = text.size();
        
        for(int i=n-1;i>=0;i--){
            if(text[i] == p[1]){
                freq2++;
            }
            if(text[i] == p[0]){
                seq += freq2;
                freq1++;
            }
        }
        
        if(p[0] == p[1])seq-= freq1;
        
     return seq + max(freq1,freq2);
    }
};