class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        
        int ans = 0 , n = s.size();
        
        for(int l=0,r=n-1;l<r;l++,r--){
            
            int idx1 = l;
            
            while(s[r] != s[idx1])idx1++;
            
            int move1 = idx1 - l;
            
            int idx2 = r;
            
            while(s[idx2] != s[l])idx2--;
            
            int move2 = r-idx2;
            
            if(move1 < move2){
                for(int i=idx1;i>l;i--)swap(s[i],s[i-1]);
            }
            else{
                for(int i=idx2;i<r;i++)swap(s[i],s[i+1]);
            }
            
            ans += min(move1,move2);
        }
   
        return ans;
    }
};