class Solution {
public:
    int garbageCollection(vector<string>& gar, vector<int>& tr) {
        
        int n=gar.size();
        unordered_map<char,int>m;
        
        if(n==0)return 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<gar[i].size();j++){
                 if(gar[i][j]=='G')m['G']=i;
                 if(gar[i][j]=='M')m['M']=i;
                 if(gar[i][j]=='P')m['P']=i;
            }
         }
        
        int t=0;  
            if(m.find('G')!=m.end()){
                for(int i=0;i<=m['G'];i++){
                    for(int j=0;j<gar[i].size();j++){
                        if(gar[i][j]=='G')t++;
                    }
                   
                }
             for(int i=0;i<m['G'];i++){
                  t+=tr[i];
             }
            }
        
         if(m.find('M')!=m.end()){
                for(int i=0;i<=m['M'];i++){
                    for(int j=0;j<gar[i].size();j++){
                        if(gar[i][j]=='M')t++;
                    }
                }
                for(int i=0;i<m['M'];i++){
                  t+=tr[i];
             }
            }
        
     if(m.find('P')!=m.end()){
                for(int i=0;i<=m['P'];i++){
                    for(int j=0;j<gar[i].size();j++){
                        if(gar[i][j]=='P')t++;
                    }
                   
                }
                for(int i=0;i<m['P'];i++){
                  t+=tr[i];
             }
            }
    return t;
    }
};