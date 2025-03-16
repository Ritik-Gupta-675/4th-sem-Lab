CREATE DATABASE if not exists my_store;
USE my_store;
CREATE TABLE if not exists product_details (
    product_id INT PRIMARY KEY,
    category VARCHAR(50),
    product_name VARCHAR(50),
    price INT,
    quantity_in_stock INT
);
INSERT INTO product_details (product_id, category, product_name, price, quantity_in_stock) VALUES
(1, 'Electronics', 'Laptop A', 1200, 50),
(2, 'Electronics', 'Phone B', 800, 100),
(3, 'Clothing', 'Shirt C', 50, 200),
(4, 'Clothing', 'Pants D', 75, 150),
(5, 'Home Goods', 'Table E', 250, 75),
(6, 'Electronics', 'Tablet F', 300, 120),
(7, 'Clothing', 'Dress G', 100, 90),
(8, 'Home Goods', 'Chair H', 150, 60),
(9, 'Electronics', 'Laptop I', 1500, 30),
(10, 'Home Goods', 'Sofa J', 500, 25);
SELECT * FROM product_details;
SELECT COUNT(*) AS total_products FROM product_details;
SELECT AVG(price) AS average_price FROM product_details;
SELECT MAX(price) AS highest_price FROM product_details;
SELECT MIN(price) AS lowest_price FROM product_details;
SELECT SUM(quantity_in_stock) AS total_quantity FROM product_details;
SELECT COUNT(DISTINCT category) AS unique_categories FROM product_details;
SELECT AVG(price) AS electronics_avg_price 
FROM product_details 
WHERE category = 'Electronics';
SELECT SUM(price * quantity_in_stock) AS total_stock_value FROM product_details;
SELECT COUNT(*) AS products_above_500 FROM product_details WHERE price > 500;
SELECT SUM(quantity_in_stock) AS clothing_stock_below_100 
FROM product_details 
WHERE category = 'Clothing' AND price < 100;

