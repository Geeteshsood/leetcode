// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    private:

    public:
    //Constructor for initializing the cache capacity with the given value.
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
        node* temp = mp[key];
        
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        
        mp.erase(key);
    }
    
    LRUCache(int cap)
    {
           
      limit = cap;
        
      head->next = tail;
      tail->prev = head;
    }
    
    int get(int key)
    {
        if(mp.find(key) != mp.end()){
            
           node* temp = mp[key];
            
           del(key);
           add(key,temp->val);
            
           return temp->val;
        }
        
        return -1;
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
       if(mp.find(key) != mp.end()){
           del(key);
       }
       else if(limit == mp.size()){
           del(tail->prev->key);
       }
        
       add(key,value); 
    }
    

};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends