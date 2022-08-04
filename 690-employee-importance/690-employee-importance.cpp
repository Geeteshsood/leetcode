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
    
    int find(int id , unordered_map<int,Employee*> &mp){
        
        int sum = mp[id]->importance;
        
        for(auto &it : mp[id]->subordinates){
            sum += find(it,mp);
        }
        
        return sum;
    }
    
    int getImportance(vector<Employee*> employees, int id) {

         unordered_map<int,Employee*> mp;
        
         for(auto &emp : employees){
             
            mp[emp->id] = emp;
         }
        
        
      return find(id,mp);
    }
};