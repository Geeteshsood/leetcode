class Solution {
public:
    int maxDiff(int num) {
        
        string s = to_string(num);
        int n = s.size();
        
        int ans = INT_MIN;
        
        for(int x=0;x<10;x++){
            for(int y=0;y<10;y++){
                
                string str = s;
                
                for(int i=0;i<n;i++){
                    
                    int ch = str[i]-'0';
                    
                    if(ch == x){
                        if(i == 0 && (y == 0))break;
                        str[i] = (y + '0');
                    }
                }
                
                int a = stoi(str);
                // if(x == 1 || x == 4)cout<<a<<endl;
                
                for(int u=0;u<10;u++){
                  for(int v=0;v<10;v++){
                      
                      string res = s;
                      
                      for(int i=0;i<n;i++){
                          
                          int ch = res[i]-'0';
                          
                          if(ch == u){
                              if(i == 0 && (v == 0))break;
                              res[i] = (v + '0');
                          }
                      }
                      
                      // cout<<str<<" "<<res<<endl;
                      
                      int b = stoi(res);
                      int val = abs(a-b);
                      
                      if(a == 0 || b == 0)continue;
                      
                      if(val > ans){
                          if(val == 899)cout<<a<<" "<<b<<endl;
                          ans = val;
                      }
                  }
                }
                
            }
        }
        
        return ans;
    }
};