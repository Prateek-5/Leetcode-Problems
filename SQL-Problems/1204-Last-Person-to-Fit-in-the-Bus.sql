/*
Table: Queue

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| person_id   | int     |
| person_name | varchar |
| weight      | int     |
| turn        | int     |
+-------------+---------+
person_id column contains unique values.
This table has the information about all people waiting for a bus.
The person_id and turn columns will contain all numbers from 1 to n, where n is the number of rows in the table.
turn determines the order of which the people will board the bus, where turn=1 denotes the first person to board and turn=n denotes the last person to board.
weight is the weight of the person in kilograms.
 

There is a queue of people waiting to board a bus. However, the bus has a weight limit of 1000 kilograms, so there may be some people who cannot board.

Write a solution to find the person_name of the last person that can fit on the bus without exceeding the weight limit. The test cases are generated such that the first person does not exceed the weight limit.

The result format is in the following example.

 

Example 1:

Input: 
Queue table:
+-----------+-------------+--------+------+
| person_id | person_name | weight | turn |
+-----------+-------------+--------+------+
| 5         | Alice       | 250    | 1    |
| 4         | Bob         | 175    | 5    |
| 3         | Alex        | 350    | 2    |
| 6         | John Cena   | 400    | 3    |
| 1         | Winston     | 500    | 6    |
| 2         | Marie       | 200    | 4    |
+-----------+-------------+--------+------+
Output: 
+-------------+
| person_name |
+-------------+
| John Cena   |
+-------------+
Explanation: The folowing table is ordered by the turn for simplicity.
+------+----+-----------+--------+--------------+
| Turn | ID | Name      | Weight | Total Weight |
+------+----+-----------+--------+--------------+
| 1    | 5  | Alice     | 250    | 250          |
| 2    | 3  | Alex      | 350    | 600          |
| 3    | 6  | John Cena | 400    | 1000         | (last person to board)
| 4    | 2  | Marie     | 200    | 1200         | (cannot board)
| 5    | 4  | Bob       | 175    | ___          |
| 6    | 1  | Winston   | 500    | ___          |
+------+----+-----------+--------+--------------+


*/

# Write your MySQL query statement below
/*
The ROWS BETWEEN UNBOUNDED PRECEDING AND CURRENT ROW is a clause used in SQL window functions, specifically to define the window frame over which the function operates. Let's break down each part of this clause:

ROWS BETWEEN: This specifies the type of frame to use. In this case, it's specifying a frame based on rows.

UNBOUNDED PRECEDING: This part defines the starting point of the window frame. "Unbounded preceding" means that the window starts at the beginning of the partition, i.e., the first row in the partition.

AND CURRENT ROW: This part defines the ending point of the window frame. "Current row" means that the window ends at the current row being processed.

Putting it all together, ROWS BETWEEN UNBOUNDED PRECEDING AND CURRENT ROW defines a window frame that includes all rows from the beginning of the partition up to and including the current row.

For example, let's say you have a table with sales data partitioned by month, and you want to calculate the cumulative sum of sales for each month. You could use this window frame in combination with a window function like SUM() to achieve this. The ROWS BETWEEN UNBOUNDED PRECEDING AND CURRENT ROW clause ensures that for each row being processed, the sum includes all sales from the beginning of the month up to and including the current row.


The another thing that is new until now is the fact that we have used LIMIT
    which is been used to limit out our result


*/



WITH CTE1 AS
(
    SELECT *,SUM(weight) OVER(ORDER BY turn ROWS BETWEEN UNBOUNDED PRECEDING AND CURRENT ROW) AS running_weight
    FROM Queue
)

SELECT person_name FROM CTE1 WHERE 
    running_weight<=1000
ORDER BY running_weight DESC
LIMIT 1
;