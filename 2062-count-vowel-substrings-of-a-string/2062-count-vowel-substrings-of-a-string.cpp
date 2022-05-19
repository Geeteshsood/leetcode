class Solution {
public:
    
    unordered_map<char,int> mp;
    
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    
    bool check(string &str){
        
        int n = str.size();
        vector<bool> res(5,false);
     
        
        for(int i=0;i<n;i++){
            if(isVowel(str[i])){
                res[mp[str[i]]] = true;
            }
            else return false;
        }
        
       return res[0] && res[1] && res[2] && res[3] && res[4];
    }
    
    int countVowelSubstrings(string s) {
        
        int n = s.size() , cnt = 0;
        
        mp['a'] = 0 , mp['e'] = 1 , mp['i'] = 2 , mp['o'] = 3 , mp['u'] = 4;
        
        for(int i=0;i<n;i++){
            string str;
            for(int j=i;j<n;j++){
                str += s[j];
                
                bool flag = check(str);
                
                if(flag){
                    cnt++;
                }
            }
        }
        
     return cnt;   
    }
};