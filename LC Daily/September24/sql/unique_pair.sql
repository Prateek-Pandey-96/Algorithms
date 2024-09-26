create table number_pairs(A int, B int);
insert into number_pairs values(1,2);
insert into number_pairs values(3,2);
insert into number_pairs values(2,4);
insert into number_pairs values(2,1);
insert into number_pairs values(5,6);
insert into number_pairs values(4,2);

-- Result
-- select t1.a, t1.b from number_pairs t1
-- left join number_pairs t2
-- on t1.a = t2.b and t1.b = t2.a
-- where t2.a is null or t1.a < t2.a
