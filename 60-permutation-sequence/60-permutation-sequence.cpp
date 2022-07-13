class Solution {
public:
    
    int fact(int n){
        int num = 1;
        for(int i=1;i<=n;i++){
            num = num*i;
        }
        return num;
    }
    
    string dfs(string &str,int n,int k){
        
        // cout<<str<<"      "<<k<<endl;
        
        if(n == 0)return "";
        
        int block = fact(n)/n;
        
        int idx =((k-1)/block);
        
        k = k - (idx*block);
        
        char ch = str[idx];
        str.erase(idx,1);
        
        return ch + dfs(str,n-1,k);
     
    }
    
    string getPermutation(int n, int k) {
        
        string str;
        
       for(int i=1;i<=n;i++){
           str += to_string(i);
       }
        
       return dfs(str,n,k);
    }
};