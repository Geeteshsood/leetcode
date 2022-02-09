// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    
    vector<string> convert(int a,int b,int c,string d)
    {
        int val2 = 0,val4 = 0;
        string val1,val3;
        
        int len = log2(a);
        val1.append(len+1,'0');
        
        while(a){
            
           int n = log2(a);
        //   cout<<n<<" "<<len<<endl;
           val1[len-n] = '1';
           
           a = a - (1<<n);
        }
    
        // cout<<val1<<endl;
        int cnt = 0;
        while(b){
            
           int x = b%10;
           if(x){
              val2 += x*(1<<cnt);
           }
           b = b/10;
           cnt++;
        }
        
        string ans,str = "0123456789ABCDEF";
        
        for(int i=0;i<8;i++){
           
           ans = str[c & (0xf)] + ans;
           c = c>>4; 
        }
        
        bool flag = false;
        for(int i=0;i<8;i++){
            if(ans[i] != '0'){
                val3 = ans.substr(i);
                flag = true;
                break;
            }
        }
        if(!flag)val3 = "0";
        
         cnt = 0;
        
        for(int i=d.size()-1;i>=0;i--){
            
            if(d[i]-'0'>9){
                val4 += pow(16,cnt)*(10 + d[i]-'A');
            }
            else val4 += pow(16,cnt)*(d[i]-'0');
            
            cnt++;
        }
        
        vector<string> sood;
        
        sood.push_back(val1);
        sood.push_back(to_string(val2));
        sood.push_back(val3);
        sood.push_back(to_string(val4));
        
        return sood;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c;
        string d;
        cin>>a>>b>>c>>d;
        
        Solution ob;
        vector<string> ans = ob.convert(a,b,c,d);
        
        for(int i = 0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
    return 0; 
}  // } Driver Code Ends