class Solution {
public:
        
    int maximumSwap(int num){
            
        string str=to_string(num);
        string s(str);
        
        sort(s.begin(),s.end(),greater<int>());
        
        int n=s.length(); 
            
        int index=0;
        char ch;
        for(int i=0;i<n;i++){
            if(str[i]!=s[i]){
                 index=i;
                 ch=s[i];
                 break;
            }
        }    
        for(int i=n-1;i>=0;i--){
            if(str[i]==ch){
                 swap(str[index],str[i]);
                 return stoi(str);
            }
        }    
            
return stoi(str);            
    }
};        
