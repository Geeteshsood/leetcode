class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        
        int ans = -1;
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<23;i++){
          int a = arr[0] , b = arr[1] , c = arr[2] , d = arr[3];
        
          int val = 1000*a + 100*b + 10*c + d;
         
          if(val >= 0 && val<= 2359 && c < 6){
              ans = max(ans,val);
          }
          next_permutation(arr.begin(),arr.end());
        }
        
        if(ans == 0)return "00:00";
        
        if(ans == -1)return "";
        
        string str;
        
        int val = ans;
        
        while(ans){
            int x = ans%10;
            str += (x+'0');
            ans = ans/10;
        }
         
         reverse(str.begin(),str.end());
        
         if(val < 1000){
             str = '0' + str;
         }
        
         string res;
        
         res = str.substr(0,2);
         res += ":";
         res += str.substr(2);
        
        return res;
    }
};