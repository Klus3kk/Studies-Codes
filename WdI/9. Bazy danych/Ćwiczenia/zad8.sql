DROP TABLE IF EXISTS Men;
CREATE TABLE Men (Day INTEGER, Month VARCHAR(15), Fir VARCHAR(20), Family VARCHAR(50));
INSERT INTO Men VALUES (1, 'September', 'Marc', 'Zuckerberg');
INSERT INTO Men VALUES (2, 'July', 'Money', 'Jagger');
INSERT INTO Men VALUES (1, 'December', 'Lloyd', 'McFly');
INSERT INTO Men VALUES (3, 'April', 'Billy', 'Nolan');
INSERT INTO Men VALUES (4, 'March', 'Gregory', 'Smith');

DROP TABLE IF EXISTS Women;
CREATE TABLE Women (Day INTEGER, Month VARCHAR(15), Fir VARCHAR(20), Family VARCHAR(50));
INSERT INTO Women VALUES (1, 'April', 'Linda', 'Jackson');
INSERT INTO Women VALUES (5, 'January', 'Maria', 'Presley');
INSERT INTO Women VALUES (4, 'September', 'Nancy', 'Sinatra');
INSERT INTO Women VALUES (3, 'February', 'Jude', 'Parker');
INSERT INTO Women VALUES (2, 'September', 'Julia', 'Lennon');

SELECT Men.Fir, Men.Family, Women.Fir, Women.Family
FROM Men
INNER JOIN Women ON Men.Day = Women.Day;

