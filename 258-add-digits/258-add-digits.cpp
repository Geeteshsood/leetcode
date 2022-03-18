class Solution {
public:
    int addDigits(int num) {
        
    while(num >= 10){
        
        int val = 0;
        
        while(num){
            int dig = num%10;
            val += dig;
            num = num/10;
        }
        
        num = val;
    }  
      
    return num;
        
    }
};