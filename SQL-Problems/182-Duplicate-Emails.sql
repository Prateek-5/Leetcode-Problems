/*
Table: Person

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| email       | varchar |
+-------------+---------+
id is the primary key (column with unique values) for this table.
Each row of this table contains an email. The emails will not contain uppercase letters.
 

Write a solution to report all the duplicate emails. Note that it's guaranteed that the email field is not NULL.

Return the result table in any order.

The result format is in the following example.

 

Example 1:

Input: 
Person table:
+----+---------+
| id | email   |
+----+---------+
| 1  | a@b.com |
| 2  | c@d.com |
| 3  | a@b.com |
+----+---------+
Output: 
+---------+
| Email   |
+---------+
| a@b.com |
+---------+
Explanation: a@b.com is repeated two times.

*/

# Write your MySQL query statement below
/*
    Intution / Basic Algorithm
    
    The GROUP BY statement groups rows that have the same values into summary rows, 
    like "find the number of customers in each country".

    The GROUP BY statement is often used with aggregate functions (COUNT(), MAX(), MIN(), SUM(), AVG()) 
    to group the result-set by one or more columns.


    The HAVING clause was added to SQL because the WHERE keyword cannot be used with aggregate functions.

    Below question is an simple implemantation of the above 2 functions 
    
    We have to aggegrate the records based on the email and keep a track of the 
    email which are present mere than once (duplicate records)

    We are using having becaus we cannot use the where clause with the agg. function like





*/




SELECT
    email as Email
FROM
    Person
GROUP BY 
    email
HAVING
    count(email) > 1;