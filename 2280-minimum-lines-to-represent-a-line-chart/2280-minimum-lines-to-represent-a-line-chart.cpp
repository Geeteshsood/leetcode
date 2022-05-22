class Solution {
public:
    typedef long double ld;
    
    int minimumLines(vector<vector<int>>& sp) {
        
        int n = sp.size();
        
        if(n == 1)return 0;
        
        vector<ld> res;
        sort(sp.begin(),sp.end());
        
        for(int i=1;i<n;i++){
           ld y = (ld)sp[i][1] - (ld)sp[i-1][1];
           ld x = (ld)sp[i][0] - (ld)sp[i-1][0];
            
           ld slope = (ld)y/x;
            // cout<<slope<<endl;
           res.push_back(slope);
        }

        int change = 0;
       
        int m = res.size()-1;
        for(int i=0;i<m;i++){
            if(res[i] != res[i+1]){
                change++;
            }
        }
        return change+1;
    }
};