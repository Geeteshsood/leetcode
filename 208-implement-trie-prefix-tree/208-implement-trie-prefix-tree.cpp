class Trie {
public:
    
    class Node{
        public : 
        Node *links[26];
        bool flag;
    };
    
    Node* root;
    
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        
        int n = word.size();
        
        Node* node = root;
        
        for(int i=0;i<n;i++){
            
            int ch = word[i]-'a';
            
            if(node->links[ch] == NULL){
                Node* temp = new Node();
                node->links[ch] = temp;
            }
            
            node = node->links[ch];
        }
        
        node->flag = true;
    }
    
    bool search(string word) {
        
        int n = word.size();
        
        Node* node = root;
        
        for(int i=0;i<n;i++){
            
            int ch = word[i]-'a';
            
            if(node->links[ch] == NULL){
                return false;
            }
            
            node = node->links[ch];
        }
        
        return node->flag;
    }
    
    bool startsWith(string prefix) {
        
        int n = prefix.size();
        
        Node* node = root;
        
        for(int i=0;i<n;i++){
            
            int ch = prefix[i]-'a';
            
            if(node->links[ch] == NULL){
                return false;
            }
            
            node = node->links[ch];
        }
        
        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */