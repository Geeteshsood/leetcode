class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        
        if(s1.size() < s2.size())swap(s1,s2);
        
        int m = s1.size() , n = s2.size();
        
        int l1 = 0 , cnt = 0;
        
        for(int i=0;i<m;i++){
            
            if(s1[i] == s2[i]){
                if(i == n-1){
                    if(i < m-1){
                        if(s1[i+1] == ' ')return true;
                    }
                    else return true;
                }
                else{
                   cnt++;
                   if(s1[i] == ' '){
                       l1 += cnt;
                       cnt = 0;
                   }
                }
            }
            else break;
        }

        // cout<<l1<<endl;
        int j = n-1;
        cnt = 0;
        
        for(int i=m-1;i>=0 && j>=0;i--,j--){
        
            if(s1[i] == s2[j]){
                if(j == 0){
                    if(i > 0){
                        if(s1[i-1] == ' '){
                            return true;
                        }
                    }
                    else return true;
                }
                else{
                  cnt++;
                  if(s1[i] == ' '){
                      l1 += cnt;
                      cnt = 0;
                  }
                }
            }
            else break;
        }
        
        // cout<<l1<<" "<<n<<endl;
        return l1 >= n;
    }
};