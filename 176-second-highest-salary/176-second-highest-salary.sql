select max(salary) as SecondHighestSalary from Employee where salary <> (select Max(salary) from Employee);
