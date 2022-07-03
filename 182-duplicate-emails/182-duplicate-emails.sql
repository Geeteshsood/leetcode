select distinct T1.email as Email from Person as T1 , Person as T2
where (T1.id <> T2.id and T1.email = T2.email);