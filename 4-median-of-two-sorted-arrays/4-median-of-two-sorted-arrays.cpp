class Solution {
public:
    
    vector<int> find(vector<int> &nums1,vector<int> &nums2,bool flag){
        
            int val1 =INT_MIN  , val2 =INT_MIN  , it = -1;
            int m = nums1.size() , n = nums2.size();
            int len = m + n;
        
        
            int start = 0 , end = m-1;
        
            while(start<=end){
                
                int i = start + (end-start)/2;
                
                if(flag) it = lower_bound(nums2.begin(),nums2.end(),nums1[i]) - nums2.begin();
                else  it = upper_bound(nums2.begin(),nums2.end(),nums1[i]) - nums2.begin();
                    
                int idx = it + i;
                
                if(len%2 == 0){
                  if(idx == (len-1)/2)val1 = nums1[i];
                  else if(idx == (len)/2)val2 = nums1[i];
                }
                else if(idx == len/2){
                     val1 = nums1[i];
                }
                
                if(idx <= (len-1)/2)start = i+1;
                else end = i-1;
                    
            }
           
      return {val1,val2};
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
              int m = nums1.size() , n = nums2.size();
              int len = m + n , sum = 0;
        
              vector<int> v1 = find(nums1,nums2,true);
              vector<int> v2 = find(nums2,nums1,false);
        
              for(int i=0;i<2;i++){
                  if(v1[i]!=INT_MIN)sum+=v1[i];
                  if(v2[i]!=INT_MIN)sum+=v2[i];
              }
 
              if(len%2 == 0)return (double)sum/2;
                    
       return (double)sum;
    }
};