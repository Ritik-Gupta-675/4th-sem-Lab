CREATE DATABASE IF NOT EXISTS LibraryDB ;
USE LibraryDB;
CREATE TABLE Books (
    BookID INT PRIMARY KEY,
    Title VARCHAR(200),
    Author VARCHAR(100),
    Publisher VARCHAR(100),
    YearPublished YEAR,
    ISBN VARCHAR(20) UNIQUE
);
CREATE TABLE Members (
    MemberID INT PRIMARY KEY,
    Name VARCHAR(100),
    Address VARCHAR(200),
    PhoneNumber VARCHAR(15),
    MembershipDate DATE
);
CREATE TABLE Transactions (
    TransactionID INT PRIMARY KEY,
    BookID INT,
    MemberID INT,
    IssueDate DATE,
    ReturnDate DATE,
    FOREIGN KEY (BookID) REFERENCES Books(BookID),
    FOREIGN KEY (MemberID) REFERENCES Members(MemberID)
);

CREATE TABLE Department (
    DepartmentID INT PRIMARY KEY,
    DepartmentName VARCHAR(100) UNIQUE
);
CREATE TABLE Employee (
    EmployeeID INT PRIMARY KEY,
    Name VARCHAR(100),
    Salary DECIMAL(10, 2),
    DepartmentID INT,
    FOREIGN KEY (DepartmentID) REFERENCES Department(DepartmentID)
);
CREATE TABLE Marks (
    StudentID INT,
    SubjectCode VARCHAR(10),
    MarksObtained INT,
    PRIMARY KEY (StudentID, SubjectCode)
);
CREATE TABLE NewData LIKE Books;
DESCRIBE TABLE Books; 
DESCRIBE TABLE NewData; 

