class Solution {
public:
    
    int maxi = INT_MIN;
    vector<int> ans,res;
    
    void find(int i,int arrused,vector<int> &al,int n,int score){
        
         if(arrused > n)return ;
        
         if(i == al.size()){
            if(score > maxi){
                ans = res;
                maxi = score;
            }
            return ;
        }
        
        res.push_back(al[i]+1);
        find(i+1,arrused+al[i]+1,al,n,score +i);
        res.pop_back();
        
        res.push_back(0);
        find(i+1,arrused,al,n,score);
        res.pop_back();
        
    }
    
    vector<int> maximumBobPoints(int n, vector<int>& al) {
        
          find(0,0,al,n,0);
       
          int sum = 0;
          for(auto &x : ans){
              sum += x;
          }
            
          ans[0] += n-sum;
        
      return ans;  
    }
};  