class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        
        int m = s1.size() , n = s2.size();
        
        if(m != n)return false;
        
        int cnt = 0;
        char c1,c2;
        
        for(int i=0;i<m;i++){
            
            if(s1[i] != s2[i]){
                if(cnt == 0){
                    c1 = s1[i] , c2 = s2[i];
                    cnt++;
                }
                else if(cnt == 1){
                    if(s1[i] != c2 || s2[i] != c1)return false;
                    cnt++;
                }
                else{
                    return false;
                }
            }
        }
        
        if(cnt == 1)return false;
        
        return true;
    }
};