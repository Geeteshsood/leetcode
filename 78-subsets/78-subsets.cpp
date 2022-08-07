class Solution { 
public:
    
    void find(int i,vector<int> &arr,vector<int> &temp,vector<vector<int>> &ans){
        
        int n = arr.size();
        
        if(i == n){
            ans.push_back(temp);
            return ;
        }
        
        find(i+1,arr,temp,ans);
        
        temp.push_back(arr[i]);
        
        find(i+1,arr,temp,ans);
        
        temp.pop_back();
        
    }
    
    vector<vector<int>> subsets(vector<int>& arr) {
        
         vector<vector<int>> ans;
         vector<int> temp;
        
         find(0,arr,temp,ans);
        
        return ans;
    }
};