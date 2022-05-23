class Solution {
public:
    
    void insert(string &s,vector<string> &res){
        
        string str;
        
        for(auto &ch : s){
            if(ch == ' '){
                res.push_back(str);
                str = "";
            }
            else str += ch;
        }
        
        res.push_back(str);
    }
    
    bool areSentencesSimilar(string s1, string s2) {
        
        if(s1.size() < s2.size())swap(s1,s2);
        
        vector<string> res1;
        vector<string> res2;
        
        insert(s1,res1);
        insert(s2,res2);
        
        int n = res1.size() , m = res2.size();
        
        if(m > n)return false;
        
        for(int i=-1;i<m;i++){
            
            if(i >= 0 && res1[i] != res2[i])return false;
            
            bool flag = true;
            
            for(int j=m-1,k=n-1;j>i;j--,k--){
                
                if(res1[k] != res2[j]){
                    flag = false;
                    break;
                }
                
            }
            
            if(flag)return true;
            
        }
        
       return false; 
    }
};