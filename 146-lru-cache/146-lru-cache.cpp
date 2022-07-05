class LRUCache {
public:
    
    class node{
        public:
        int key;
        int val;
        
        node* next;
        node* prev;
        
        node(int _key , int _val){
            key = _key;
            val = _val;
        }
        
    };
    
    int limit = 0;
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    
    unordered_map<int,node*> mp;
    
    LRUCache(int capacity) {
      
      limit = capacity;
        
      head->next = tail;
      tail->prev = head;
        
    }
    
    void print(){

        node* temp = head;
        
        temp = temp->next;
        
        while(temp->key != -1){
            cout<<temp->key<<" , ";
            temp = temp->next;
        }
        cout<<endl;
    }
    
    void add(int key,int value){
        
       node* temp = new node(key,value);
        
       node* nex = head->next;
       temp->next = nex;
       temp->prev = head;
        
       nex->prev = temp;
       head->next = temp;
        
       mp[key] = temp;
    }
    
    void del(int key){
        // print();
        node* temp = mp[key];
        
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        
        mp.erase(key);
        // print();
    }
    
    int get(int key) {
        
        if(mp.find(key) != mp.end()){
            
           node* temp = mp[key];
            
           del(key);
           add(key,temp->val);
            
           return temp->val;
            
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        
       // cout<<key<<endl;
        
       if(mp.find(key) != mp.end()){
           del(key);
       }
       else if(limit == mp.size()){
           del(tail->prev->key);
       }
        
       add(key,value);
        // print();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */