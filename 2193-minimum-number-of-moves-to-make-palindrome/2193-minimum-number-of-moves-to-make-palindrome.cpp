class Solution {
public:
    
    int check(int x,int y,string &s){
        
       vector<int> first(26,-1),last(26,-1);
       
       for(int i=x;i<=y;i++){
           if(first[s[i]-'a'] == -1)first[s[i]-'a'] = i;
           last[s[i]-'a'] = i;
       }
       
       int ch = -1 , mini = INT_MAX;
       
       for(int i=0;i<26;i++){
           if(first[i] != -1 && last[i] != -1){
               int moves = first[i]-x + y - last[i];
               if(moves < mini){
                   mini = moves;
                   ch = i;
               }
           }
       } 
        
       for(int i=first[ch];i>x;i--)swap(s[i],s[i-1]);
       for(int i=last[ch];i<y;i++)swap(s[i],s[i+1]);
        
       return mini;
    }
    
    int find(int i,int j,string &s){
        
        int n = s.size();
        
        if(i > j){
            return 0;
        }
          
        if(s[i] == s[j]){
            return find(i+1,j-1,s);
        }
        else{
           
           int moves = check(i,j,s);
           
           if(moves == INT_MAX)return -1;
            
           return moves + find(i+1,j-1,s); 
        }
        
        return -1;
    }
    
    int minMovesToMakePalindrome(string s) {
        
        int n = s.size();
        return find(0,n-1,s);
        
    }
};