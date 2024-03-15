/*
Table: ActorDirector

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| actor_id    | int     |
| director_id | int     |
| timestamp   | int     |
+-------------+---------+
timestamp is the primary key (column with unique values) for this table.
 

Write a solution to find all the pairs (actor_id, director_id) where the actor has cooperated with the director at least three times.

Return the result table in any order.

The result format is in the following example.

 

Example 1:

Input: 
ActorDirector table:
+-------------+-------------+-------------+
| actor_id    | director_id | timestamp   |
+-------------+-------------+-------------+
| 1           | 1           | 0           |
| 1           | 1           | 1           |
| 1           | 1           | 2           |
| 1           | 2           | 3           |
| 1           | 2           | 4           |
| 2           | 1           | 5           |
| 2           | 1           | 6           |
+-------------+-------------+-------------+
Output: 
+-------------+-------------+
| actor_id    | director_id |
+-------------+-------------+
| 1           | 1           |
+-------------+-------------+
Explanation: The only pair is (1, 1) where they cooperated exactly 3 times.

*/

# Write your MySQL query statement below
/*
    Intution / Basic Algorithm

    The basic idea of the folloinw gquestion is that we need to apply the group by clause for
    mulptiple cols and once we are done with the same we have the 3rd coln time stamp
    which is not includede in the group by so we apply the condition the the count of the timestamp
    because each time stamp will contribute to 1 so we put in the condition that the count of timestamp
    should be greater than or equal to 3

*/


SELECT actor_id,director_id FROM ActorDirector GROUP BY actor_id,director_id
HAVING COUNT(timestamp) >=3;