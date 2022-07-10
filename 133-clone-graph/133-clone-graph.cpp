class Solution {
public:
    
    unordered_map<Node*, Node*> mp;
    
    Node* clone(Node* node){
        
        if(node == NULL)return NULL;
        
        Node* temp = new Node(node->val);
        
        mp[node] = temp;
        
        for(auto &cur : node->neighbors){
            
            Node* copy = new Node(cur->val);
            
            if(mp.find(cur) == mp.end()){
                 temp->neighbors.push_back(clone(cur));
            }
            else{
                temp->neighbors.push_back(mp[cur]);
            }
            
        }
        
        return temp;
    }
    
    Node* cloneGraph(Node* node) {
        return clone(node);
    }
};