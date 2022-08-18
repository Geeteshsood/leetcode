class Solution {
public:
    
    bool isValid(int i,int j,int m,int n){
        
        return !(i < 0 || j < 0 || i >= m || j >= n);
        
    }
    
    bool dfs(int i,int j,int idx,vector<vector<char>> &board,string &word,vector<vector<int>> &vis){
       
       int m = board.size() , n = board[0].size();
      
       if(idx == word.size())return true; 
        
       if(!isValid(i,j,m,n) || word[idx] != board[i][j] || vis[i][j]){
           return false;
       }

        vis[i][j] = true;
        // cout<<i<<" "<<j<<" -> "<<idx<<endl;
        
       bool f1 = dfs(i+1,j,idx + 1,board,word,vis); 
       bool f2 = dfs(i-1,j,idx + 1,board,word,vis);        
       bool f3 = dfs(i,j+1,idx + 1,board,word,vis); 
       bool f4 = dfs(i,j-1,idx + 1,board,word,vis); 
        
       vis[i][j] = false;
        
       return f1 || f2 || f3 || f4;        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        int m = board.size() , n = board[0].size();
        vector<vector<int>> vis(m,vector<int> (n,false));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == word[0]){
                    if(dfs(i,j,0,board,word,vis))return true;
                }
            }
        }
        
        return false;
    }
};