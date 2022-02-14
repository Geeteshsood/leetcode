class Solution {
public:
    long long smallestNumber(long long num) {
        
        
        string str = to_string(num);
        
        int n = str.size();
        
        if(str[0] == '-'){
            
            sort(str.rbegin(),str.rend()-1);
            
        }
        else{
           
            sort(str.begin(),str.end());
            
            int cnt = 0;
            
            for(int i=0;i<n;i++){
                if(str[i] == '0')cnt++;
                else break;
            }
            
            if(cnt<n)swap(str[0],str[cnt]);
            
        }
        
        
        return stol(str);
    }
};