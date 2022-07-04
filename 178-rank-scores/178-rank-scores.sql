
select s1.score,count(distinct s2.score) 'rank' from Scores s1 join scores s2 where s1.score <= s2.score group by s1.id order by s1.score desc;