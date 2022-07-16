class Solution {
public:
    
    class Node{
        public:
        Node* links[2];
    };
     
    Node* root;
    
    void insert(string &s){
        
        Node* node = root;
        
        int n = s.size();
        
        for(int i=0;i<n;i++){
            
            int x = s[i]-'0';
            
            if(node->links[x] == NULL){
                Node* temp = new Node();
                node->links[x] = temp;
            }
            
            node = node->links[x];
        }
        
    }
    
    int findmaxy(string &s){
        
        Node* node = root;
        int n = s.size() , val = 0;
        
        for(int i=0;i<n;i++){
            
            int x = !(s[i]-'0');
            
            if(node->links[x] == NULL){
                x = !x;
                
                if(x)val += (1<<(30-i));
                
                node = node->links[x];
            }
            else{
                
                if(x)val += (1<<(30-i));
                
                node = node->links[x];
            }
        }
        
        return val;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        
        unordered_map<int,string> mp;
        
        root = new Node();
        
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            
            int num = nums[i];
            string str;
            
            for(int j=30;j>=0;j--){
                
                  if(num >= (1<<j)){
                      num -= (1<<j);
                      str += '1';
                  }
                  else str += '0';
                
            }
            
            mp[i] = str;
            
            insert(str);
        }
        
        int ans = INT_MIN;
        
        for(int i=0;i<n;i++){
            
            int num = nums[i];

            int val = findmaxy(mp[i]);
            ans = max(ans,val^nums[i]);
        }
        
        return ans;
    }
};