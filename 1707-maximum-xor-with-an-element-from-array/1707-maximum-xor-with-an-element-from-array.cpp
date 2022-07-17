class Solution {
public:
    
    class Node{
        public:
        Node* links[2];
    };
    
    Node* root;

    void insert(int num){
        
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
    
    int findmaxy(int num){
        
        int val = 0;        
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
    
        return val;
    }
    
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        
        root = new Node();
        
        int n = queries.size() , m = nums.size();
        
        vector<pair<int,pair<int,int>>> que;
        
        for(int i=0;i<n;i++){
            que.push_back({queries[i][1],{queries[i][0],i}});
        }
        
        sort(que.begin(),que.end());
        
        sort(nums.begin(),nums.end());
        
        vector<int> res(n);
        int j = 0;
        
        for(auto &q : que){
            
            int val = q.first , num = q.second.first , id = q.second.second;
           
            while(j < m && nums[j] <= val){
                insert(nums[j]);
                j++;
            }
              
            if(j == 0){
                res[id] = -1;
                continue;
            }
              
            int temp = findmaxy(num);
            res[id] = temp^num;
        }
        
        return res;
    }
};