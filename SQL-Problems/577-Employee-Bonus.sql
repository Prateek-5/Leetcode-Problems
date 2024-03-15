/*
Table: Employee

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| empId       | int     |
| name        | varchar |
| supervisor  | int     |
| salary      | int     |
+-------------+---------+
empId is the column with unique values for this table.
Each row of this table indicates the name and the ID of an employee in addition to their salary and the id of their manager.
 

Table: Bonus

+-------------+------+
| Column Name | Type |
+-------------+------+
| empId       | int  |
| bonus       | int  |
+-------------+------+
empId is the column of unique values for this table.
empId is a foreign key (reference column) to empId from the Employee table.
Each row of this table contains the id of an employee and their respective bonus.
 

Write a solution to report the name and bonus amount of each employee with a bonus less than 1000.

Return the result table in any order.

The result format is in the following example.

 

Example 1:

Input: 
Employee table:
+-------+--------+------------+--------+
| empId | name   | supervisor | salary |
+-------+--------+------------+--------+
| 3     | Brad   | null       | 4000   |
| 1     | John   | 3          | 1000   |
| 2     | Dan    | 3          | 2000   |
| 4     | Thomas | 3          | 4000   |
+-------+--------+------------+--------+
Bonus table:
+-------+-------+
| empId | bonus |
+-------+-------+
| 2     | 500   |
| 4     | 2000  |
+-------+-------+
Output: 
+------+-------+
| name | bonus |
+------+-------+
| Brad | null  |
| John | null  |
| Dan  | 500   |
+------+-------+


*/
# Write your MySQL query statement below

/*
    Write a solution to report the name and bonus amount of each employee with a bonus less than 1000.

    Through the following statement we got to know that we need to include all the employee who are eith present but with
    less than 1000 bonus and also include the empployee whoc have null bonus those arre also considered as the employee with
    less than 1000 bonus so for that matter we have put a left outter join and put condition for the following consstranin
        less than 1000 bonus
        null bonus
    
    Here is the picture of how the records would look after the left outter join
    | empId | name   | supervisor | salary | empId | bonus |
    | ----- | ------ | ---------- | ------ | ----- | ----- |
    | 3     | Brad   | null       | 4000   | null  | null  |
    | 1     | John   | 3          | 1000   | null  | null  |
    | 2     | Dan    | 3          | 2000   | 2     | 500   |
    | 4     | Thomas | 3          | 4000   | 4     | 2000  |

    Visualize this for better undestanding



*/


    SELECT e.name,b.bonus
    FROM Employee e
    LEFT JOIN Bonus b
    ON e.empId=b.empid
    WHERE b.bonus < 1000 OR b.bonus IS NULL; 

