class Solution {
public:
    int longestValidParentheses(string s) {
        
        int n = s.size();
        
        stack<int> st;
        
        for(int i=0;i<n;i++){
            // cout<<i<<" "<<st.size()<<endl;
            if(s[i] == '('){
                st.push(s[i]);
                continue;
            }
            
            int sum = 0;
            bool flag = true;
            
            while(st.size() && st.top() != ')' ){
                if(st.top() == '('){
                     flag = false;
                     st.pop();
                     sum += 2;
                     st.push(sum + '0'); 
                     break;
                }
                else{
                    sum += st.top()-'0';
                    st.pop();
                }
            }
            
            if(flag){
                if(sum)st.push(sum + '0');
                st.push(')');
            }
            
             // cout<<i<<" "<<st.size()<<endl;
        }
        // cout<<st.size()<<endl;
        int sum = 0 , ans = 0;
        
        while(st.size()){
    
            if(st.top() == ')' || st.top() == '('){
                ans = max(ans,sum);
                sum = 0;
            }
            else {
                // cout<<st.top()-'0'<<endl;
                sum += st.top()-'0';
            }
            
            st.pop();
        }
        
        return max(sum,ans);
    }
};