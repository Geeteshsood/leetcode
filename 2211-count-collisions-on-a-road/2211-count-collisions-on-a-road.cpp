class Solution {
public:
    int countCollisions(string s) {
        
        int n = s.size() , collide = 0;
        vector<char> st;
        
        for(int i=0;i<n;i++){
            
            if(s[i] != 'L'){
                st.push_back(s[i]);
            }
            else{
                char cur = s[i];
                
                if(st.size()){
                    if(st.back() == 'R' && cur == 'L'){
                        collide+=2;
                    }
                    else if(st.back() == 'S' && cur == 'L'){
                        collide+=1;
                    }
                    cur = 'S';
                    st.pop_back();
                }
                
                if(cur == 'S')st.push_back(cur);
            }
            
        }
        
        int cnt = 0;
        n = st.size();
        
        for(int i=n-1;i>=0;i--){
            if(st[i] == 'S')cnt++;
            else if(st[i] == 'R' && cnt > 0)collide++;
        }
        
      
        return collide;
    }
};