class Solution {
public:
    int countCollisions(string dir) {
        
       int n = dir.size();
       int left = 0 , right = n-1;
        
       while(left<n && dir[left] == 'L')left++;
       while(right>=0 && dir[right] == 'R')right--;
        
       int collide = 0;
        
       for(int i=left;i<=right;i++){
           if(dir[i] != 'S'){
               collide++;
           }
       }
        
     return collide;   
    }
};