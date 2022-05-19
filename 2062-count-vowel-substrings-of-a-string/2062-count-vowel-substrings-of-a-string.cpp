class Solution {
public:
    
    unordered_map<char,int> mp;

    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    
    int countVowelSubstrings(string s) {
        
        int n = s.size() , cnt = 0;
        
        vector<int> res(5,0),temp(5,0),set(5,0);
        
        mp['a'] = 0 , mp['e'] = 1 , mp['i'] = 2 , mp['o'] = 3 , mp['u'] = 4;
        
        int j = 0 , k =0;
        
        for(int i=0;i<n && j<n;i++){
            
           if(isVowel(s[i])){
               
               res[mp[s[i]]]++;
               
               temp = res;
               
               while(k < i && k < n){
                   
                   if(temp[0] && temp[1] && temp[2] && temp[3] && temp[4]){
                       // cout<<k<<" "<<i<<endl;
                       cnt++;
                   }
                   else break;
                   
                   temp[mp[s[k]]]--;
                   k++;
               }
               
               k = j;
           }
           else{
               j = i+1;
               res = set;
           }

        }
        
     return cnt;   
    }
};