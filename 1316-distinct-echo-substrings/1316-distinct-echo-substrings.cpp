class Solution {
public:
    
    int distinctEchoSubstrings(string str) {
        
        int n = str.size();
        
        string_view s = str;
        
        set<string_view> se;
        
        for(int g=1;g<n;g+=2){
            
            for(int i=0,j=g;i<n && j<n;i++,j++){
                
                int len = (g+1)/2;
                
                string_view s1 = s.substr(i,len);
                string_view s2 = s.substr(i+len,len);
                
                if(s1 == s2){
                    if(!se.count(s1))se.insert(s1);
                }    
            }
        }
        
    return se.size();
    }
};