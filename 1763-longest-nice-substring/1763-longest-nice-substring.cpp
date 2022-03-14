class Solution {
public:
    string longestNiceSubstring(string s) {
        
        unordered_set<char> se(s.begin(),s.end());
        
        for(int i=0;i<s.size();i++){
            
            if(se.count(toupper(s[i])) && se.count(tolower(s[i])))continue;
            
            auto left  = longestNiceSubstring(s.substr(0,i));
            auto right = longestNiceSubstring(s.substr(i+1));
            
            if(left.size() >= right.size())return left;
            else return right;
        }
        
        return s;
    }
};