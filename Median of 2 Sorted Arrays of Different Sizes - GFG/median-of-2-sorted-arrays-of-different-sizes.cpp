// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int m = nums1.size() , n = nums2.size();
        int len = m + n;
        
        if(m == 0){
            if(n%2 == 0)return (nums2[(n/2)-1] + nums2[n/2])/2.0;
            else return nums2[n/2];
        }
        if(m > n)return MedianOfArrays(nums2,nums1);
        
        int start = 0 , end = m;
        
        while(start <= end){
            
            int cut1 = start + (end - start)/2;
            int cut2 = ((len+1)/2) - cut1;
            
            int left1 = cut1 <= 0 ? INT_MIN : nums1[cut1-1];
            int left2 = cut2 <= 0 ? INT_MIN : nums2[cut2-1];
            
            int right1 = cut1 >= m ? INT_MAX : nums1[cut1];
            int right2 = cut2 >= n ? INT_MAX : nums2[cut2];
            
            
            if(left1 > right2){
                 end = cut1 - 1;
            }
            else if(left2 > right1){
                 start = cut1 + 1;
            }
            else{
                if(len % 2 == 0){
                     return (max(left1,left2) + min(right1,right2))/2.0;
                }
                else{
                     return max(left1,left2);
                }
            }
        }
        
     return -1; 
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends