class Solution {
public:
    
    int find(string s,int x,int y,char c1,char c2){
        
        int gain = 0;
        string str;
        
        for(int i=0;i<s.size();i++){
        
          if(s[i] == c1){
             if(str.size() && str.back() == c2){
                 gain += x;
                 str.pop_back();
             }
             else str += s[i];
          }
          else str += s[i];
            
        }
        // cout<<str<<" "<<gain<<endl;
        
        string res;
        for(int i=0;i<str.size();i++){
        
          if(str[i] == c2){
             if(res.size() && res.back() == c1){
                 gain += y;
                 res.pop_back();
             }
             else res += str[i];
          }
          else res += str[i];
            
        }
        
        return gain;
        
    }
    
    int maximumGain(string s, int x, int y) {
        
        if(y > x){
            return find(s,y,x,'a','b');
        }
        
        return find(s,x,y,'b','a');
    }
};