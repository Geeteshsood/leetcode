class Solution {
public:
    bool reorderedPowerOf2(int n) {
        
        string s = to_string(n);
        
        vector<int> nums1(10);
        
        for(auto &ch : s){
            nums1[ch-'0']++;
        }
        
        int sz = s.size();
        
        string str = s;
        sort(str.begin(),str.end());
        
        int num = stoi(str);
        
        int dig = log2(num);
        int val = pow(2,dig);
        
        while(true){
            
           vector<int> nums(10);
              
           int x = val;
           int cnt = 0;
            
           while(x > 0){
               nums[x%10]++;
               x = x/10;
               cnt++;
           }
            
           bool flag = true;
            
           for(int i=0;i<10;i++){
               if(nums1[i] != nums[i]){
                   flag = false;
                   break;
               }
           }
            
           if(flag)return true;
            
           if(cnt > sz)break;
            
           val = 2*val;
        }
        
        return false;
    }
};