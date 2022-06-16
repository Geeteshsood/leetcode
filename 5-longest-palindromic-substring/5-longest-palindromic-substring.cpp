class Solution {
public:
    
    int check(int i,int j,string &s){
        
        int n = s.size();
        
        while(i >= 0 && j < n && s[i] == s[j]){
              i--;
              j++;
        }
        
      return j-i-1;  
    }
    
    string longestPalindrome(string s) {
        
        int n = s.size() , st = -1 , len = 0;
        
        for(int i=0;i<n;i++){
            
            int len1 = check(i,i+1,s);
            int len2 = check(i,i,s);
            
            // cout<<i<<" "<<len1<<" "<<len2<<endl;
            
            if(len1 > len2 && len1 > len){
                st = i-(len1-1)/2;  
            }
            else if(len2 > len1 && len2 > len){
                st = i-(len2/2);
            }
            
            len = max({len,len1,len2});
        }
        
     return s.substr(st,len);
    }
};