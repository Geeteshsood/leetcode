class Solution {
public:

     class Node{
        public:
        
        Node* links[26];
        bool flag;
    };
    
    Node* root;

    void insert(string word) {
        
        Node* node = root;
        
        for(auto &ch : word){
            
            if(!node->links[ch-'a']){
               Node* temp = new Node();
               node->links[ch-'a'] = temp;
            }
            
            node = node->links[ch-'a'];
        }
        
        node->flag = true;
    }
    
    string longestCommonPrefix(vector<string>& str) {
        
        root = new Node();
        
        int n = str.size();
        
        for(int i=0;i<n;i++){
            insert(str[i]);
        }

        string ans;
        Node* node = root;
        
        while(node){
            
            int cnt = 0 , idx = -1;
            
            for(int i=0;i<26;i++){

                if(node->links[i] && !node->flag){
                    idx = i;
                    cnt++;
                }   
            }
    
            if(cnt == 1)ans += (idx+'a') ,node = node->links[idx];
            else break;
        }
        
        return ans;
    }
};