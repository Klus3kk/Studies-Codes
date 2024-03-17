DROP TABLE IF EXISTS Persons;
CREATE TABLE Persons (MainKey INTEGER, Name VARCHAR(10));
INSERT INTO Persons VALUES (1, 'Alan');
INSERT INTO Persons VALUES (2, 'Ewa');
INSERT INTO Persons VALUES (3, 'Jan');
INSERT INTO Persons VALUES (4, 'Ola');
INSERT INTO Persons VALUES (5, 'Ula');
SELECT * FROM Persons;

drop table IF EXISTS Authors;
create table Authors (Who INTEGER, What INTEGER);
INSERT INTO Authors VALUES (1, 1);
INSERT INTO Authors VALUES (1, 2);
INSERT INTO Authors VALUES (2, 2);
INSERT INTO Authors VALUES (2, 3);
INSERT INTO Authors VALUES (3, 3);
INSERT INTO Authors VALUES (5, 4);
SELECT * FROM Authors;

drop table IF EXISTS Publishers;
create table Publishers (MainKey INTEGER, Pub VARCHAR(5));
INSERT INTO Publishers VALUES (1, 'Hey');
INSERT INTO Publishers VALUES (2, 'Abc');
INSERT INTO Publishers VALUES (3, 'Abc');
INSERT INTO Publishers VALUES (4, 'Hey');
SELECT * FROM Publishers;

SELECT DISTINCT Name
FROM Persons, Authors, Publishers
WHERE Pub = 'Hey'
AND Publishers.MainKey = Authors.What
AND Authors.Who = Persons.MainKey;