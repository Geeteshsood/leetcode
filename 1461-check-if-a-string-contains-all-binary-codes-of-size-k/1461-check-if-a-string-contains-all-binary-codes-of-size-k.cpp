class Solution {
public:
    bool hasAllCodes(string s, int k) {
       
        unordered_set<string> se;
        
        int n = s.size();
        string str;
        
        if(k > n)return false;
        
        for(int i=0;i<k;i++){
            str += s[i];
        }
        
        se.insert(str);
        
        for(int i=k;i<n;i++){
            
            string temp = str.substr(1) + s[i];
            se.insert(temp);
            
            str = temp;
        }
        
        return se.size() == (1<<k);
    }
};