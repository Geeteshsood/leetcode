class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        
        string zero,one,two;
        sort(digits.rbegin(),digits.rend());
        
        int sum = 0;
        
        for(auto &i : digits){
           sum += i;
           if(i%3 == 0)zero += i + '0';
           else if(i%3 == 1)one += i + '0'; 
           else if(i%3 == 2)two += i + '0'; 
        }
        
        if(sum % 3 == 1){
            if(one.size())one = one.substr(0,one.size()-1);
            else two = two.substr(0,two.size()-2);
        }
        else if(sum % 3 == 2){
            if(two.size())two = two.substr(0,two.size()-1);
            else one = one.substr(0,one.size()-2); 
        }
        
        zero+=one + two;
        
        int n = zero.size();
        if(n > 1 && zero[0] == zero[n-1] && zero[0] == '0')return "0";
        
        sort(zero.rbegin(),zero.rend());
        
     return zero;  
    }
};