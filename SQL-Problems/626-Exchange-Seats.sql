/*
Table: Seat

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| student     | varchar |
+-------------+---------+
id is the primary key (unique value) column for this table.
Each row of this table indicates the name and the ID of a student.
id is a continuous increment.
 

Write a solution to swap the seat id of every two consecutive students. If the number of students is odd, the id of the last student is not swapped.

Return the result table ordered by id in ascending order.

The result format is in the following example.

 

Example 1:

Input: 
Seat table:
+----+---------+
| id | student |
+----+---------+
| 1  | Abbot   |
| 2  | Doris   |
| 3  | Emerson |
| 4  | Green   |
| 5  | Jeames  |
+----+---------+
Output: 
+----+---------+
| id | student |
+----+---------+
| 1  | Doris   |
| 2  | Abbot   |
| 3  | Green   |
| 4  | Emerson |
| 5  | Jeames  |
+----+---------+
Explanation: 
Note that if the number of students is odd, there is no need to change the last one's seat.

*/

# Write your MySQL query statement below
/*
    Intution / Basic Algorithm

    The following is the brute force approch of the following problem
        WHERE we calculated the next and prev for each and every id and the 
            if the id is even the consider the prev_id
            if the id is odd and the it's next is not greater than the max(id) we have in ur table then next_id
            if the 2nd case is false then id
        AS id
    This is the basic algorithm used for the following problem note we only require to show the table to the user
    and not update the existing table once we ar done with the same we need to order the result by id
    WITH CTE1 AS
(
    SELECT *,
    (id-1) AS prev,
    (id+1) AS next
    FROM Seat
)

    SELECT (
            CASE 
                WHEN id%2=0  THEN prev
                WHEN id%2<>0 AND next <= (SELECT MAX(id) FROM Seat) THEN next
                ELSE id
            END
        ) AS id,
        student
    FROM CTE1
        ORDER BY id;



    Another method for the following question is to use the window function for the same
        LAG OVER(ORDER BY id) AS prev_id
        LEAD OVER(ORDER BY if) As next_id
    Once we are done with the same we need to apply the same logic as mentioned above we just need to change the 
    constraing in the CASE
    | id | student | prev_id | next_id |
    | -- | ------- | ------- | ------- |
    | 1  | Abbot   | null    | 2       |
    | 2  | Doris   | 1       | 3       |
    | 3  | Emerson | 2       | 4       |
    | 4  | Green   | 3       | 5       |
    | 5  | Jeames  | 4       | null    |

*/



WITH CTE1 AS
(
    SELECT *,
    LAG(id) OVER(ORDER BY id) AS prev_id,
    LEAD(id) OVER(ORDER BY id) as next_id
    FROM Seat
)

SELECT (
    CASE
        WHEN id%2 =0 THEN prev_id
        WHEN id%2=1 AND next_id IS NOT NULL THEN next_id
        ELSE id
    END) AS id,
    student 
    
    FROM CTE1
    ORDER BY id;
