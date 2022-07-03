select T1.name as Employee from
Employee as T1 , Employee as T2
where T1.managerId = T2.id and 
T1.salary > T2.salary;