class Solution {
public:
    
    int ans = INT_MAX;
    int time[12];
    
    void find(int i,int val,vector<int> &jobs,int k){
        
        int n = jobs.size();
    
        if(i == n){
            ans = min(ans,val);
            return ;
        }
         
        
        for(int j=0;j<k;j++){
            
           if(j > 0 && time[j] == time[j-1])continue;
            
            time[j] += jobs[i];
            if(time[j] < ans)find(i+1,max(val,time[j]),jobs,k);
            time[j] -= jobs[i];
        }
        
    }
    
    int minimumTimeRequired(vector<int>& jobs, int k) {
        
        memset(time,0,sizeof(time));
        
        find(0,0,jobs,k);
        
        return ans;
    }
};