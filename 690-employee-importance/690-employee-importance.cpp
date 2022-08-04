/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    
    int find(int id , vector<vector<int>> &adj,vector<int> &dp){
        
        if(dp[id] == INT_MIN)return 0;
        
        int sum = dp[id];
        
        dp[id] = INT_MIN;
        
        for(auto &it : adj[id]){
            sum += find(it,adj,dp);
        }
        
        return sum;
    }
    
    int getImportance(vector<Employee*> employees, int id) {

         vector<int> dp(2001,INT_MIN);
         vector<vector<int>> adj(2001);
        
         for(auto &emp : employees){
             
            int i = emp->id;
            int imp = emp->importance;
            dp[i] = imp;
            for(auto &it : emp->subordinates){
                  adj[i].push_back(it);
            }
         }
        
        
      return find(id,adj,dp);
    }
};