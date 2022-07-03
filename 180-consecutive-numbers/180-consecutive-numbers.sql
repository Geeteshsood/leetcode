select distinct T1.num as ConsecutiveNums from 
Logs T1, Logs T2, Logs T3 
where
T1.id = T2.id - 1 and T2.id = T3.id - 1 and
T1.num = T2.num and T2.num = T3.num;
