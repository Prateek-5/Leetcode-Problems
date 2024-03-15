/*
Table: Triangle

+-------------+------+
| Column Name | Type |
+-------------+------+
| x           | int  |
| y           | int  |
| z           | int  |
+-------------+------+
In SQL, (x, y, z) is the primary key column for this table.
Each row of this table contains the lengths of three line segments.
 

Report for every three line segments whether they can form a triangle.

Return the result table in any order.

The result format is in the following example.

 

Example 1:

Input: 
Triangle table:
+----+----+----+
| x  | y  | z  |
+----+----+----+
| 13 | 15 | 30 |
| 10 | 20 | 15 |
+----+----+----+
Output: 
+----+----+----+----------+
| x  | y  | z  | triangle |
+----+----+----+----------+
| 13 | 15 | 30 | No       |
| 10 | 20 | 15 | Yes      |
+----+----+----+----------+

*/
# Write your MySQL query statement below
/*
    Intution / Basic Algorithm

    For a line segment to be a triangle if we pick any two points they should be greatter than the 3rd
    On similar line we are writting the following solution

    The follwing example explains us how dowe  use the case in out sql queries
    Important points
    mention CASE to start and END to end
    write the condition in between

*/


SELECT *,
    CASE
        WHEN (x+y) > z AND (x+z) > y AND (y+z) > x THEN 'Yes' ELSE 'No'
    END AS triangle
FROM Triangle; 