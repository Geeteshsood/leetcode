 
select Department.name as department,Employee.name as Employee,salary 
from Employee join Department on Employee.departmentId = Department.id
where (Employee.departmentId , salary) in 
(select departmentId,max(salary) from Employee group by DepartmentId) ;