class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        
        unordered_set<string> se;
        
        for(auto &str : emails){
            
            int n = str.size();
            bool flag = true;
            string s;
            
            for(int i=0;i<n;i++){
                
                if(str[i] == '.' && flag)continue;
                
                if(str[i] == '+'){
                     while(i < n && str[i] != '@'){
                         i++;
                     }
                }
                
                if(str[i] == '@')flag = false;
                
                s += str[i];
            }
            
            se.insert(s);
        }
        
        return se.size();
    }
};