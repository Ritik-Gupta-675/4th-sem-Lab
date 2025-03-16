DROP DATABASE universitydb;
CREATE DATABASE UniversityDB;
USE UniversityDB;
CREATE TABLE Departments (
    department_id INTEGER PRIMARY KEY,
    department_name VARCHAR(100) UNIQUE NOT NULL
);
CREATE TABLE Students (
    student_id INTEGER PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    email VARCHAR(100) UNIQUE,
    department_id INTEGER,
    FOREIGN KEY (department_id) REFERENCES Departments(department_id)
);
INSERT INTO Departments (department_id, department_name) VALUES (101, 'Computer Science');
INSERT INTO Departments (department_id, department_name) VALUES (102, 'Electrical Engineering');
INSERT INTO Departments (department_id, department_name) VALUES (103, 'Mechanical Engineering');
INSERT INTO Students (student_id, name, email, department_id) VALUES (1, 'Alice', 'alice@example.com', 101);
INSERT INTO Students (student_id, name, email, department_id) VALUES (2, NULL, 'bob@example.com', 102);
INSERT INTO Students (student_id, name, email, department_id) VALUES (3, 'Charlie', 'alice@example.com', 103);
INSERT INTO Students (student_id, name, email, department_id) VALUES (4, 'David', 'david@example.com', 104);
describe Students;
ALTER TABLE Students 

MODIFY email VARCHAR(100) NOT NULL;

SHOW CREATE TABLE Students;
ALTER TABLE Students DROP FOREIGN KEY students_ibfk_1;
ALTER TABLE Students DROP COLUMN department_id;
-- Step 1: Drop the existing foreign key constraint
ALTER TABLE Students DROP FOREIGN KEY students_ibfk_1; 
ALTER TABLE Students 
ADD CONSTRAINT fk_department
FOREIGN KEY (department_id) REFERENCES Departments(department_id) ON DELETE CASCADE;
DELETE FROM Departments WHERE department_id = 102;
SELECT * FROM Students WHERE department_id = 102;
SELECT * FROM Students WHERE email IS NULL;







