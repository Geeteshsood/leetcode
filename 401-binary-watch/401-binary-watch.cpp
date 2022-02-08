class Solution {
public:
    vector<string> readBinaryWatch(int total) {
        
        vector<string> ans;
        
        int min = 12;
        int sec = 60;
        
        for(int i=0;i<min;i++){
            
            int n1 = i,count = 0;
                
             while(n1){
               int rsb = n1 & -n1;
               n1 = n1 - rsb;
               count++;
             }
            
            for(int j=0;j<sec;j++){
                
                int n = j,cnt = 0;
                
                while(n){
                  int rsb = n & -n;
                  n = n - rsb;
                  cnt++;
                }
                
                if(cnt == total - count){
                    // cout<<cnt<<" "<<count<<endl;
                    string str = to_string(i) + ":" ;
                    
                    if(j/10)str += to_string(j);
                    else str += "0" + to_string(j);
                    
                    ans.push_back(str);
                }
                
            }
        }
        
       return ans; 
    }
};