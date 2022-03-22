class Solution {
public:
    
    int find(string s,int x,int y,char c1,char c2,int cnt){
        
        if(cnt > 1)return 0;
        
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
        
        return gain + find(str,y,x,c2,c1,cnt+1);
        
    }
    
    int maximumGain(string s, int x, int y) {
        
        if(y > x){
            return find(s,y,x,'a','b',0);
        }
        
        return find(s,x,y,'b','a',0);
    }
};