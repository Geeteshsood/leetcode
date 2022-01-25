class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        
        string zero,one,two;
        sort(digits.rbegin(),digits.rend());
        
        for(auto &i : digits){
           if(i%3 == 0)zero += i + '0';
           else if(i%3 == 1)one += i + '0'; 
           else if(i%3 == 2)two += i + '0'; 
        }
        
        int x = one.size() , y = two.size();
        int z = min(x,y);
        int a = 3*((x-z)/3) , b = 3*((y-z)/3);
        
        if(z == 0){
            zero += one.substr(0,a) + two.substr(0,b);
        }
        else if(x == y){
            zero += one + two;
        }
        else if(x > y){
            if((x-z)%3 == 0){
                zero += one + two;
            }
            else if((x-z)%3 == 1){
                zero+=two + one.substr(0,z);
                zero += one.substr(z,a);
            }
            else if((x-z)%3 == 2){
                zero += two.substr(0,z-1) + one.substr(0,z-1);
                int a = 3*((x-z+1)/3);
                zero += one.substr(z-1,a);
            }    
        }
        else{
            if((y-z)%3 == 0){
                zero += one + two;
            }
            else if((y-z)%3 == 1){
                zero+=one+two.substr(0,z);
                zero += two.substr(z,b);
            }
            else if((y-z)%3 == 2){
                zero += one.substr(0,z-1) + two.substr(0,z-1);
                int a = 3*((y-z+1)/3);
                zero += two.substr(z-1,a);
            }  
        }
        
         int n = zero.size();
        if(n > 1 && zero[0] == zero[n-1] && zero[0] == '0')return "0";
        
        sort(zero.rbegin(),zero.rend());
        
     return zero;  
    }
};