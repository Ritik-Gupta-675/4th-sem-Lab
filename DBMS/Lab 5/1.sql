CREATE TABLE Sales (
    SaleID INT PRIMARY KEY,
    Product VARCHAR(50),
    Category VARCHAR(50),
    Quantity INT,
    Price DECIMAL(10,2),
    SaleDate DATE
);
INSERT INTO Sales (SaleID, Product, Category, Quantity, Price, SaleDate) VALUES
(1, 'Laptop', 'Electronics', 5, 800, '2024-01-10'),
(2, 'Phone', 'Electronics', 10, 600, '2024-01-15'),
(3, 'TV', 'Electronics', 3, 1200, '2024-02-01'),
(4, 'Chair', 'Furniture', 15, 100, '2024-02-10'),
(5, 'Table', 'Furniture', 7, 300, '2024-02-15'),
(6, 'Laptop', 'Electronics', 8, 750, '2024-03-01'),
(7, 'Chair', 'Furniture', 12, 110, '2024-03-05'),
(8, 'TV', 'Electronics', 5, 1300, '2024-03-10'),
(9, 'Sofa', 'Furniture', 4, 500, '2024-03-15'),
(10, 'Phone', 'Electronics', 6, 650, '2024-03-20');

SELECT Product, SUM(Quantity * Price) AS TotalSales 
FROM Sales 
GROUP BY Product;

SELECT Product, COUNT(*) AS TransactionCount 
FROM Sales 
GROUP BY Product;

SELECT Category, SUM(Quantity) AS TotalQuantitySold 
FROM Sales 
GROUP BY Category;

SELECT Product, AVG(Price) AS AveragePrice 
FROM Sales 
GROUP BY Product;

SELECT Category, MAX(Price) AS HighestSalePrice 
FROM Sales 
GROUP BY Category;

-- 2. Using GROUP BY with HAVING

SELECT Product, SUM(Quantity) AS TotalQuantity 
FROM Sales 
GROUP BY Product 
HAVING SUM(Quantity) > 10;

SELECT Category, SUM(Quantity * Price) AS TotalSales 
FROM Sales 
GROUP BY Category 
HAVING SUM(Quantity * Price) > 5000;

SELECT Product, AVG(Price) AS AveragePrice 
FROM Sales 
GROUP BY Product 
HAVING AVG(Price) > 500;

SELECT Category, COUNT(DISTINCT Product) AS ProductCount 
FROM Sales 
GROUP BY Category 
HAVING COUNT(DISTINCT Product) > 2;

SELECT Product, SUM(Quantity * Price) AS TotalSales 
FROM Sales 
WHERE Category = 'Electronics' 
GROUP BY Product 
HAVING SUM(Quantity * Price) > 8000;

-- 3. Using ORDER BY

SELECT Product, SUM(Quantity * Price) AS TotalSales 
FROM Sales 
GROUP BY Product 
ORDER BY TotalSales DESC;
SELECT Category, SUM(Quantity) AS TotalQuantitySold 
FROM Sales 
GROUP BY Category 
ORDER BY TotalQuantitySold ASC;
SELECT Product, AVG(Price) AS AveragePrice 
FROM Sales 
GROUP BY Product 
ORDER BY AveragePrice DESC;
SELECT Category, COUNT(*) AS TransactionCount 
FROM Sales 
GROUP BY Category 
ORDER BY TransactionCount DESC;
SELECT Product, SUM(Quantity * Price) AS TotalSales 
FROM Sales 
GROUP BY Product 
HAVING SUM(Quantity * Price) > 5000 
ORDER BY TotalSales DESC;
