e , i, j
​
we dont need 3 variables , whereas we only need 2 variables egg and floor.
​
because.=> breaking 2 eggs  at floor 1 - 3
is same as breaking 2 eggs at floor  4-6.
​
​
e , f
time complexity will be  e* f^2
​
TLE
​
AC Solution.
e*f*logf
​
​
how ? -> watch pepcoding solution for understanding .
​
egg = 2 ,floor = 10.
​
1   2   3    4    5    6    7    8     9    10
​
there will be  1 out of these 10 floor which will be our ans.
we have to choose best of them .
​
lets say we choose 4   ->  break egg       1-3 floor   ways = 5.
not break egg   5-10 floor  ways = 10.
it is not in our hands that egg will break or not . it is luck so we hope for worst here .
because we have to give minimum number of attempts with certainity.
minimum number of attempts is in our hand by choosing which floor
but after choosing floor egg will break or not it is not in our hands.
10
9
8
7        ways = 10 (worst case)
6
5
4
3
2        ways = 5(worst case)
1