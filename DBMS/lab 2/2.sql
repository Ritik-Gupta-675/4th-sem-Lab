CREATE DATABASE IF NOT EXISTS UniversityDB;
USE UniversityDB;

DROP TABLE IF EXISTS Instructors;
CREATE TABLE Instructors (
    InstructorID INT PRIMARY KEY,
    Name VARCHAR(100),
    Department VARCHAR(50)
);
CREATE TABLE Courses (
    CourseID INT PRIMARY KEY,
    CourseName VARCHAR(100) UNIQUE,
    Credits INT DEFAULT 3,
    InstructorID INT,
    FOREIGN KEY (InstructorID) REFERENCES Instructors(InstructorID)
);
CREATE TABLE Employees (
    EmployeeID INT PRIMARY KEY,
    Name VARCHAR(100),
    Salary DECIMAL(10, 2),
    Email VARCHAR(100) UNIQUE,
    CHECK (Salary > 5000)
);
ALTER TABLE Employees
ADD CONSTRAINT Unique_Email UNIQUE (Email);
