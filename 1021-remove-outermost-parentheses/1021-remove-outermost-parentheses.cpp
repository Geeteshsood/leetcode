class Solution {
public:
    
   string removeOuterParentheses(string s) {
       
        string a="";
        int n=s.size();
        if(n==0)return s;
       
        unordered_map<char,char>m;
        m['(']=')';
        int i=0;
        stack<char> st;
        string g="";
       
        while(i<n){
            
            st.push(s[i]);
            i++;
            int j=i;
            string a="";
            
            while(!st.empty() && j<n){
                char c=s[j];
                if(c=='('){
                    st.push(c);
                    a+=c;   
                }
                else{
                    st.pop();
                    a+=c;
                }
                
                    j++;
            }
                        
            a.pop_back();
            i=j;
            g+=a;
        }
       
        return g;
    }    
};