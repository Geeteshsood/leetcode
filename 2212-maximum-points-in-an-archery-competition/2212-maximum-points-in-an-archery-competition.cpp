class Solution {
public:
    
    int maxi = INT_MIN;
    vector<int> ans,v;
    
    void find(int i,int moves,vector<int> &al,int n,int sum){
        
         if(moves > n)return ;
        
         if(i == al.size()){
            if(sum > maxi){
//                    for(auto &i : v)cout<<i<<" ";
                
//                      cout<<endl;
//                      cout<<moves<<" "<<endl;
        
                int temp = v[0];
                v[0] = temp+ n - moves;;
                ans = v;
                v[0] = temp;
                maxi = sum;
            }
            return ;
        }
        
        v.push_back(al[i]+1);
         find(i+1,moves+al[i]+1,al,n,sum +i);
        v.pop_back();
        
        v.push_back(0);
         find(i+1,moves,al,n,sum);
        v.pop_back();
        
    }
    
    vector<int> maximumBobPoints(int n, vector<int>& al) {
        
     find(0,0,al,n,0);
        
      return ans;  
    }
};