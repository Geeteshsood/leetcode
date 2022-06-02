class Solution {
public:
    
      double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
          
        int a=nums1.size();
        int b=nums2.size();
          
        vector<int>num;
        int i=0,j=0,k=0;
          
        while(i<a && j<b){
            if(nums1[i]<=nums2[j]){
                num.push_back(nums1[i]);
                i++;
            }
             else{
               num.push_back(nums2[j]);
                j++;
           
            }
        }
          
        while(i<a){
            num.push_back(nums1[i]);
            i++;
        }
          
        while(j<b){
            num.push_back(nums2[j]);
            j++;
        }
        
        int c=a+b;
        int mid=c/2;

        if(c%2==0){
            return (double)(num[mid-1]+num[mid])/2;;
        }
        else{
            return num[mid];
        }
    }
};