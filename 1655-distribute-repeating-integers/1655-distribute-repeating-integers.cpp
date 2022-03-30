class Solution {
public:
    
    bool find(int i,vector<int> &freq,vector<int> &quantity){
        
        int n = freq.size() , m = quantity.size();
        
        if(i == m){
            return true;
        }
    
        for(int j=0;j<n;j++){
            
            if(quantity[i] <= freq[j]){
                
                freq[j]-=quantity[i];
                if(find(i+1,freq,quantity))return true;
                freq[j]+=quantity[i];
            }
        }
        
        return false;
    }
    
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        
        vector<int> freq;
        unordered_map<int,int> mp;
        
        for(auto &i : nums){
            mp[i]++;
        }
        
        for(auto &[num,fq] : mp){
            freq.push_back(fq);
        }
        
        sort(quantity.begin(), quantity.end(), greater());
        sort(freq.begin(), freq.end());
        
        return find(0,freq,quantity);
    }
};