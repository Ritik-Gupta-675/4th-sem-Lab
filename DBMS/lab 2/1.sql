CREATE DATABASE SchoolDB;
USE SchoolDB;

CREATE TABLE Students (
    StudentID INT PRIMARY KEY,
    Name VARCHAR(100),
    Age INT,
    Class VARCHAR(50),
    Email VARCHAR(100)
);
ALTER TABLE Students
ADD PhoneNumber VARCHAR(15);

ALTER TABLE Students
MODIFY Age TINYINT;

ALTER TABLE Students
DROP COLUMN Email;

DROP TABLE Students;

RENAME TABLE Students TO StudentRecords;
