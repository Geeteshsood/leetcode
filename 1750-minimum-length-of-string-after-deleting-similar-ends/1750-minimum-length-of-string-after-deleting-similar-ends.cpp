class Solution {
public:
    int minimumLength(string s) {
        
        int n = s.size();
        
        int i = 0 , j = n-1;
        
        while(i < j && s[i] == s[j]){
            
            while(i < j && s[i] == s[i+1]){
                i++;
            }
            i++;
            
            while(j > i && s[j] == s[j-1]){
                j--;
            }
            j--;
            
            // cout<<i<<" "<<j<<endl;
        }
        
        
        return max(0,j-i+1);
    }
};