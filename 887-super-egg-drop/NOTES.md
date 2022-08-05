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
​
choosing index is in our hands  we want to have  best of the worst case  means minimum from all the
worst case here max(5,10) = 10.
​
as we go up down case will increase and up case will decrease .
egg -> (break,notbreak)
-> down inc , up dec                                  <-  down dec,up inc
1      2      3      4                            9       10
2,20   3,14   4,12 , 5,10                          14,3     18 ,2
​
if we reach  4 and up is greater than down then we do not need go to left.
as it will only up and decrease down which is of our no benefit.
as we are not going to get the best ans below 4 .
​
because choosing floor is in our hand .
below 4 worst case is going to increase .
​
we have to take best of the worst cases. so need to go below 4.