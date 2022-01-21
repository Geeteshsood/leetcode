class Solution {
public:
    
    unordered_map<int,unordered_map<int,int>> dp;
    
    bool find(unordered_set<int> &stones,int val,int jump,int &dest){
        
            // cout<<val<<" "<<jump<<endl;
            if(val == dest)return true;
            else if(val > dest)return false;

           // cout<<val<<" "<<jump<<endl;
            if(dp.count(val) && dp[val].count(jump))return dp[val][jump];
        
            bool flag = false;
            val += jump;
        
            if(stones.count(val+1))flag = flag || find(stones,val+1,jump+1,dest);
            if(stones.count(val))flag = flag || find(stones,val,jump,dest);    
            if(jump-1>0 && stones.count(val-1))flag = flag || find(stones,val-1,jump-1,dest);    
        
            val-= jump;
        
     return dp[val][jump] = flag;
    }
    
    bool canCross(vector<int>& stone) {
        
        int dest = stone.back();
        unordered_set<int> stones(stone.begin(),stone.end());
        
        if(stone[1]!=1)return false;
        
        return find(stones,1,1,dest);
        
    }
};