class Solution {
public:
    int numberOfSteps(int num) {
        
        int cnt = 0;
        
        while(num){
           
            if(num%2 == 0){
                num = num/2;
            }
            else num = num-1;
            
            cnt++;
        }
       
        return cnt;
    }
};