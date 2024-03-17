DROP TABLE IF EXISTS t1;
CREATE TABLE t1 (a INTEGER, b INTEGER, x INTEGER);
INSERT INTO t1 VALUES (1, 0, 5);
INSERT INTO t1 VALUES (0, 1, 4);
INSERT INTO t1 VALUES (1, 2, 5);
SELECT * FROM t1;
drop table IF EXISTS t2;
create table t2 (y INTEGER, c INTEGER, d INTEGER);
INSERT INTO t2 VALUES (5, 20, 2);
INSERT INTO t2 VALUES (5, 22, 4);
INSERT INTO t2 VALUES (5, 24, 6);
SELECT * FROM t2;

update t1 set x = 2 * a + b where b < 2;
update t2 set y = d where d > 2;
select c,d,y from t1,t2 where b < x order by a asc;