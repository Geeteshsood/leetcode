select name as Customers from Customers where Customers.id NOT IN (select Customers.id from Customers,Orders
where Customers.id = Orders.customerId);
