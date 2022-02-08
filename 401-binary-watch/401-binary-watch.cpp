class Solution {
public:
    vector<string> readBinaryWatch(int total) {
        
        vector<string> ans;
        
        for(int min=0;min<12;min++){
            for(int sec=0;sec<60;sec++){
                
                if(__builtin_popcount(min) + __builtin_popcount(sec) == total){
                    
                       string str = to_string(min) + ":";
                    
                       if(sec<10)str += '0';
                    
                       str += to_string(sec);
                     
                       ans.push_back(str);
                }
            }
        }
        
       return ans; 
    }
};