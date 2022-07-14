class Trie {
public:
    
    class Node{
        public:
        
        Node* links[26];
        bool flag = false;
        
        bool contain(char ch){
            
            return (links[ch-'a'] != NULL);
            
        }
        
        void put(char ch , Node* temp){
            
            links[ch-'a'] = temp;
            
        }
        
        Node* next(char ch){
            
            return links[ch-'a'];
        }

    };
    
    Node* root;
    
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        
        Node* node = root;
        
        for(int i=0;i<word.size();i++){
            
            if(!node->contain(word[i])){
                node->put(word[i],new Node());
            }
            
            node = node->next(word[i]);
        }
        
        node->flag = true;
        
    }
    
    bool search(string word) {
        
        Node* node = root;
        
        for(int i=0;i<word.size();i++){
            
            if(!node->contain(word[i])){
                return false;
            }
            
            node = node->next(word[i]);
        }
        
        return node->flag;
    }
    
    bool startsWith(string prefix) {
        
         Node* node = root;
        
        for(int i=0;i<prefix.size();i++){
            
            if(!node->contain(prefix[i])){
                return false;
            }
            
            node = node->next(prefix[i]);
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