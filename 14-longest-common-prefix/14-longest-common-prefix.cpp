class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        
        int n = str.size();
        
        int lim = str[0].size();
        
        for(int i=1;i<n;i++){
            int j = 0 , k = 0;
            while(j < str[i].size() && lim && str[i][j] == str[0][k] ){
                j++,k++;
            }
            
            lim = min(j,lim);
        }
        
        return str[0].substr(0,lim);
    }
};