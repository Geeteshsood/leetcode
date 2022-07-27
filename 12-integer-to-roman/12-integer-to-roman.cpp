class Solution {
public:
    string intToRoman(int n) {
        
      map<int,string> mp{{1000,"M"},{900,"CM"},
                       {500,"D"},{400,"CD"},
                       {100,"C"},{90,"XC"},
                       {50,"L"},{40,"XL"},
                       {10,"X"},{9,"IX"},
                       {5,"V"},{4,"IV"},
                       {1,"I"}};

        string str;
        
      for(auto it = mp.rbegin();it != mp.rend();it++){
          
          int val = it->first;
          string res = it->second;
          
          if(n >= val){
              int x = n/val;
              int num = val*x;
              
              while(x){
                  str += res;
                  x--;
              }
              n -= num;
              
          }
      } 
      
        return str;
    }
};