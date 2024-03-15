/*
Table: Orders

+-----------------+----------+
| Column Name     | Type     |
+-----------------+----------+
| order_number    | int      |
| customer_number | int      |
+-----------------+----------+
order_number is the primary key (column with unique values) for this table.
This table contains information about the order ID and the customer ID.
 

Write a solution to find the customer_number for the customer who has placed the largest number of orders.

The test cases are generated so that exactly one customer will have placed more orders than any other customer.

The result format is in the following example.

 

Example 1:

Input: 
Orders table:
+--------------+-----------------+
| order_number | customer_number |
+--------------+-----------------+
| 1            | 1               |
| 2            | 2               |
| 3            | 3               |
| 4            | 3               |
+--------------+-----------------+
Output: 
+-----------------+
| customer_number |
+-----------------+
| 3               |
+-----------------+
Explanation: 
The customer with number 3 has two orders, which is greater than either customer 1 or 2 because each of them only has one order. 
So the result is customer_number 3.
 

Follow up: What if more than one customer has the largest number of orders, can you find all the customer_number in this case?

*/


# Write your MySQL query statement below
/*

This is called as the common table expression we can write out query on top of this 
    For concept this is how the records are stored in the common table expression 


        | customer_number | OrderperCust |
        | --------------- | ------------ |
        | 1               | 1            |
        | 2               | 1            |
        | 3               | 2            |

    The above table contain the customer_number and the order per customer made we need the customer that make the max
    orders
    1 such method is we can order the above result in desc order by OrderpreCust
    but the drawback of the following would be if 2 customers whould have made the same number of order then we would miss
    out the 2nd customer

    So for that purpose we run a query where we have the max orderpreCust(max orders a customer made)

    Once we have the following number we can iterate through the following query and filter out those result using the normal
    where query and return the customer_number


*/


WITH CTE AS
(SELECT customer_number,COUNT(order_number) as OrderperCust FROM Orders GROUP BY customer_number)




SELECT customer_number FROM CTE WHERE OrderperCust=(SELECT MAX(OrderperCust) FROM CTE);