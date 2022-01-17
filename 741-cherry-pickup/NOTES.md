rQ FIND 2 paths and find max sum.
​
for every possible path find max(path1+ path2) till they reach at n-1 , n-1.
4 possibilities
down down
down , right
right , down
right , right
we are asking at any point maximum cherries from these 4 directions.
and adding our point cherries.
if(we are standing at one point)
else we are standing at two different points.
we are considering those points where both path reach end.
path 2
(0,0) --------------------|
|                                    |
|                                    |
|---------------------  (n-1,n-1)
path1
r1 + c1 = r2 + c2
we need only 3 variables r1,c1,r2.