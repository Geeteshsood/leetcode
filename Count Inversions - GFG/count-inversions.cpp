// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    typedef long long int ll;
    
    ll cnt = 0;
    
    vector<ll> merge_sort(ll arr[],ll start,ll end){
        
        if(start > end)return {};
        else if(start == end)return {arr[start]};
        
        ll mid = start + (end - start)/2;
        
        vector<ll> left = merge_sort(arr,start,mid);
        vector<ll> right = merge_sort(arr,mid+1,end);
        
        ll i=0 , j=0 , m = left.size() , n = right.size();
        
        vector<ll> res;
        
        while(i < m && j < n){
            
            if(left[i] > right[j]){
                res.push_back(right[j]);
                cnt += m-i;
                j++;
            }
            else{
                res.push_back(left[i]);
                i++;
            }
        }
        
        while(i<m){
            res.push_back(left[i]);
            i++;
        }
        
        while(j < n){
            res.push_back(right[j]);
            j++;
        }
        
        return res;
        
    }
    
    long long int inversionCount(long long arr[], long long n)
    {

        vector<ll> res = merge_sort(arr,0,n-1);
        
        // for(auto &i : res){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        return cnt;
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends