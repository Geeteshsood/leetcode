class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=-1;
        int j=-1;
        int n=s.size();
        unordered_map<char,int>m;
        int len=0;
        
        while(true){
            // cout<<i<<" "<<j<<endl;
            bool b1=false;
            bool b2=false;
            
            //acquire
            while(i<n-1){
                b1=true;
                i++;
                m[s[i]]++;
                if(m[s[i]]==2){
                    break;
                }
                else{
                    int a=i-j;
                    if(a>len)len=a;
                }
            }
                 // cout<<i<<" "<<j<<endl;
            //release
            while(j<i){
                b2=true;
                j++;
                m[s[j]]--;
                
                if(m[s[j]]==1)break;   
             }
            
          if(b1==false && b2==false)break;
            
        }
        
        return len;
    }
};