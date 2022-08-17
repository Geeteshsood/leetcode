class Solution {
public:
    
    int minimumLength(string s){
        
        int n=s.size();
        
        int i=0;
        int j=n-1;
        
        while(i<j && s[i]==s[j]){
            char c=s[i];
            while(i<j && s[i]==c)i++;
            while(i<=j && s[j]==c)j--;
        }
       
        // cout<<i<<" "<<j<<endl;
       
        return j-i+1;
        
    }
};