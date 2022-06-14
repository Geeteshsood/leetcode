class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        vector<int> rmin(n+1);
        int lmaxi=INT_MIN;
        int count=0;
         rmin[n]=INT_MAX;
        
          for(int i=n-1;i>=0;i--){
            rmin[i]=min(rmin[i+1],arr[i]);
          }
        
        
          for(int i=0;i<n;i++){
             
                lmaxi=max(lmaxi,arr[i]);
             
                if(lmaxi<=rmin[i+1]) 
                    count++;
          }
        
//           for(int i=0;i<=n;i++){
//               cout<<rmin[i]<<" ";
//           }
//           cout<<endl;
        
        return count;
    }
};