/*
Table: Customers

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
+-------------+---------+
id is the primary key (column with unique values) for this table.
Each row of this table indicates the ID and name of a customer.
 

Table: Orders

+-------------+------+
| Column Name | Type |
+-------------+------+
| id          | int  |
| customerId  | int  |
+-------------+------+
id is the primary key (column with unique values) for this table.
customerId is a foreign key (reference columns) of the ID from the Customers table.
Each row of this table indicates the ID of an order and the ID of the customer who ordered it.
 

Write a solution to find all customers who never order anything.

Return the result table in any order.

The result format is in the following example.

 

Example 1:

Input: 
Customers table:
+----+-------+
| id | name  |
+----+-------+
| 1  | Joe   |
| 2  | Henry |
| 3  | Sam   |
| 4  | Max   |
+----+-------+
Orders table:
+----+------------+
| id | customerId |
+----+------------+
| 1  | 3          |
| 2  | 1          |
+----+------------+
Output: 
+-----------+
| Customers |
+-----------+
| Henry     |
| Max       |
+-----------+

*/

# Write your MySQL query statement below

/*
    Intution / Basic Algorithm
    | id | name  | id   | customerId |
    | -- | ----- | ---- | ---------- |
    | 1  | Joe   | 2    | 1          |
    | 2  | Henry | null | null       |
    | 3  | Sam   | 1    | 3          |
    | 4  | Max   | null | null       |

    This is how the table will look if we apply left join
    on the customer table all the records of the the customer table would be 
    populated and the records which are not present as per the join then for those
    null will be populated in the corresponding columns of the orders table




*/

-- SELECT 
--     c.name as Customers
-- FROM
--     Customers  c
-- LEFT JOIN
--     Orders o
-- ON
--     c.id=o.customerId
-- WHERE
--     o.customerId IS null;

/*
    This is an another approch thought which we can attempt this question if 
    through the nested query we featched out the id of the people who have made a purchase 
    adn have an entry in the Orders table once we have the hold of those id we can iterate throught the
    customers table again and featch out the id which are not present in the this query

*/

select c.name as Customers
FROM Customers c where c.id not in(select c.id from Customers c join Orders o ON c.id=o.customerId);