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
            // cout<<cnt<<endl;
            string s;
            if(cnt < n){
                s = str[cnt];
            }
            // cout<<s<<endl;
            s.append(cnt,'0');
            // cout<<s<<endl;
            
            if(cnt < n)s += str.substr(cnt+1);
            // cout<<s<<endl;
            return stol(s);
            
        }
        
        
        return stol(str);
    }
};