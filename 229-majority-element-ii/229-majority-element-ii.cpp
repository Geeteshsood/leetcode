class Solution {
public:
    vector<int> majorityElement(vector<int>& nums){
            
        int n=nums.size() , cnt1 = 0 , cnt2 = 0;   
        int major1 = -1 , major2 = -1;
        
        for(int i=0;i<n;i++){
            
            if(nums[i] == major1){
                cnt1++;
            }
            else if(nums[i] == major2){
                cnt2++;
            }
            else if(cnt1 == 0)major1 = nums[i],cnt1 = 1;
            else if(cnt2 == 0)major2 = nums[i],cnt2 = 1;
            else cnt1--,cnt2--;
        }
        
        int freq1 = 0 , freq2 = 0;
        
        for(int i=0;i<n;i++){
            if(nums[i] == major1)freq1++;
            else if(nums[i] == major2)freq2++;
        }
        
        bool f1 = freq1 > (n/3) , f2 = freq2 > n/3;
        
        if(f1 && f2)return {major1,major2};
        else if(f1)return {major1};
        else if(f2)return {major2};
        
        return {};
    }
};