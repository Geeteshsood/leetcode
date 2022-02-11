2 imp points
​
getting run time error due to pow(n,k-1)
​
n^(k-1) might be integer overflow
​
so we have to do constant modulo
like ex=>
​
for(int i=0;i<k;i++)
n = (n*n)%mod.
so that it never get overflow.
2nd
val -= x;
​
val can get negative so how to modulo in subtraction
val = (val - x + mod)%mod