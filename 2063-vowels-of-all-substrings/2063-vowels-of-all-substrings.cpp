class Solution {
public:
    
    typedef long long ll;
    
    bool isVowel(char ch){
        
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')return true;
        
        return false;
    }
    
    long long countVowels(string word) {
        
       ll n = word.size();
        
       ll sum = 0 , cur = 0 , prev = 0;
        
       if(isVowel(word[0]))prev = 1,sum = 1;
        
       for(ll i=1;i<n;i++){
           
           if(isVowel(word[i])){
               cur = prev + i+1;
           }
           else{
               cur = prev;
           }
           
           sum += cur;
           prev = cur;
       }
    
        return sum;
    }
};