class Solution {
public:
    bool isValid(string s) {
        
        unordered_map<char,int> mp;
        int n = s.size();
        
        mp['('] = 1 , mp[')'] = -1;
        mp['['] = 2 , mp[']'] = -2;
        mp['{'] = 3 , mp['}'] = -3;
        
        stack<char> st;        
        
        for(int i=0;i<n;i++){
            if(mp[s[i]] > 0){
                st.push(s[i]);
                continue;
            }
            else{
                if(st.size() && mp[s[i]] == -(mp[st.top()])){
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
        }
        
        return st.empty();
    }
};