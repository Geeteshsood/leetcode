select Department.name as Department , e1.name as Employee , salary 
from Employee e1 join Department on e1.departmentId = Department.id 
where 3 > (select count(distinct e2.salary) from Employee e2 
where e1.departmentId = e2.departmentId and e1.salary < e2.salary);