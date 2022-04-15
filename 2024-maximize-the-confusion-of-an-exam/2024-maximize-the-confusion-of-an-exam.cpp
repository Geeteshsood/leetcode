class Solution {
public:
    int maxConsecutiveAnswers(string str , int k) {
        
        int n = str.size() , len = 0;
        
        int tr = 0 , fl = 0 , j = 0;
        
        for(int i=0;i<n;i++){
            
            if(str[i] == 'T')tr++;
            else fl++;
            
            if(tr <= k || fl <= k){
                len = max(len,i-j+1);
            }
            else{
                if(str[j] == 'T')tr--;
                else fl--;
                j++;
            }
        }
        
      return len;  
    }
};