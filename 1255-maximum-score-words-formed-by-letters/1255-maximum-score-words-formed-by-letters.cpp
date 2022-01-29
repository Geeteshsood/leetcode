class Solution {
public:

    int find(int i,vector<int> &score,vector<int> &cnt,vector<string> &words){
        
        if(i == words.size())return 0;
        
         int x  = 0 , y = 0;
        
         y = find(i+1,score,cnt,words);
        
         vector<int> count(cnt.begin(),cnt.end());
        
         bool flag = true;
         int sum = 0;
        
         for(auto &x : words[i]){
             count[x-'a']--;
             sum += score[x-'a'];
             if(count[x-'a'] < 0){
                 flag = false;
                 break;
             }
         }
        
         if(flag){
             x = sum + find(i+1,score,count,words);
         }
        
     return max(x,y); 
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        
        int n = words.size();
    
        vector<int> cnt(26);
        for(auto &x : letters){
            cnt[x-'a']++;
        }
        
        return find(0,score,cnt,words);
        
    }
};