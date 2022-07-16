class Solution {
public:
    
    class Node{
        public:
        Node* links[2];
    };
     
    int findMaximumXOR(vector<int>& nums) {
        
        Node* root = new Node();
        
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            
            int num = nums[i];
            Node* node = root;
            
            for(int j=31;j>=0;j--){
                
               int bit = (num>>j) & 1;
                
               if(node->links[bit] == NULL){
                   Node* temp = new Node();
                   node->links[bit] = temp;
               }
                
               node = node->links[bit];
            }
        }
        
        int ans = INT_MIN;
        
        for(int i=0;i<n;i++){
            
            int num = nums[i] , val = 0;
            Node* node = root;
            
            for(int j=31;j>=0;j--){
                
               int bit = (num>>j) & 1;
                
               if(node->links[!bit] == NULL){
                  
                   if(bit)val += (1<<j);
                   
                   node = node->links[bit];
                   
               }
               else{ 
                 if(!bit)val += (1<<j);
                  
                 node = node->links[!bit];
               }
            }
            
            ans = max(ans,val^nums[i]);
        }
        
      return ans;
    }
};