class Solution {
public:
    int maxConsecutiveAnswers(string str, int k) {
        
        int n = str.size();
        
        vector<int> tr(n),fl(n);
        
        if(str[0] == 'T')tr[0] = 1;
        else fl[0] = 1;
            
        for(int i=1;i<n;i++){
            if(str[i] == 'T'){
                tr[i] = tr[i-1] + 1;
                fl[i] = fl[i-1];
            }
            else{
                fl[i] = fl[i-1] + 1;
                tr[i] = tr[i-1];
            }
        }
        
        int len = 1 , t = 0 , f = 0;
        
        for(int i=0;i<n;i++){
            
            if(i != 0) t = tr[i-1] , f = fl[i-1];
            
            int start = i+len , end = n-1 , ans = i;
            
            while(start <= end){
                
               int mid = start + (end - start)/2;
                   
               int x = tr[mid] - t;
               int y = fl[mid] - f;
                
               if(x <= k || y <= k){
                   ans = mid;
                   start = mid+1;
               }
               else end = mid - 1;
            }
            
            len = max(len , ans - i + 1);
        }
        
      return len;  
    }
};