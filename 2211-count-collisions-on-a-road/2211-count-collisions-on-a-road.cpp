class Solution {
public:
    int countCollisions(string dir) {
        
        int n = dir.size() , collide = 0 , cnt = 0 , prev = -1;
        
        for(int i=0;i<n;i++){
            
            if(dir[i] == 'L'){
                if(i == 0){
                    prev = 0;
                    continue;
                }
                
                if(dir[i-1] != 'R' && cnt > 0){
                    collide++;
                }
                else if(dir[i-1] == 'R'){
                    collide += 2;
                }
                
                 int j = i-2;
                 while(j >= 0 && j > prev && dir[j] == 'R'){
                     collide++;
                     j--;
                 }
            }
            else{
                int j = i-1;
                if(i > 0 && dir[i] == 'S'){
                    while(j>=0 && dir[j] == 'R'){
                        collide++;
                        j--;
                    }
                }
                cnt++;
            }
            
            if(dir[i] != 'R')prev = i;
        }
        
     return collide;   
    }
};