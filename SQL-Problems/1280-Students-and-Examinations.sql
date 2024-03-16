/*
Table: Students

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| student_id    | int     |
| student_name  | varchar |
+---------------+---------+
student_id is the primary key (column with unique values) for this table.
Each row of this table contains the ID and the name of one student in the school.
 

Table: Subjects

+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| subject_name | varchar |
+--------------+---------+
subject_name is the primary key (column with unique values) for this table.
Each row of this table contains the name of one subject in the school.
 

Table: Examinations

+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| student_id   | int     |
| subject_name | varchar |
+--------------+---------+
There is no primary key (column with unique values) for this table. It may contain duplicates.
Each student from the Students table takes every course from the Subjects table.
Each row of this table indicates that a student with ID student_id attended the exam of subject_name.
 

Write a solution to find the number of times each student attended each exam.

Return the result table ordered by student_id and subject_name.

The result format is in the following example.

 

Example 1:

Input: 
Students table:
+------------+--------------+
| student_id | student_name |
+------------+--------------+
| 1          | Alice        |
| 2          | Bob          |
| 13         | John         |
| 6          | Alex         |
+------------+--------------+
Subjects table:
+--------------+
| subject_name |
+--------------+
| Math         |
| Physics      |
| Programming  |
+--------------+
Examinations table:
+------------+--------------+
| student_id | subject_name |
+------------+--------------+
| 1          | Math         |
| 1          | Physics      |
| 1          | Programming  |
| 2          | Programming  |
| 1          | Physics      |
| 1          | Math         |
| 13         | Math         |
| 13         | Programming  |
| 13         | Physics      |
| 2          | Math         |
| 1          | Math         |
+------------+--------------+
Output: 
+------------+--------------+--------------+----------------+
| student_id | student_name | subject_name | attended_exams |
+------------+--------------+--------------+----------------+
| 1          | Alice        | Math         | 3              |
| 1          | Alice        | Physics      | 2              |
| 1          | Alice        | Programming  | 1              |
| 2          | Bob          | Math         | 1              |
| 2          | Bob          | Physics      | 0              |
| 2          | Bob          | Programming  | 1              |
| 6          | Alex         | Math         | 0              |
| 6          | Alex         | Physics      | 0              |
| 6          | Alex         | Programming  | 0              |
| 13         | John         | Math         | 1              |
| 13         | John         | Physics      | 1              |
| 13         | John         | Programming  | 1              |
+------------+--------------+--------------+----------------+
Explanation: 
The result table should contain all students and all subjects.
Alice attended the Math exam 3 times, the Physics exam 2 times, and the Programming exam 1 time.
Bob attended the Math exam 1 time, the Programming exam 1 time, and did not attend the Physics exam.
Alex did not attend any exams.
John attended the Math exam 1 time, the Physics exam 1 time, and the Programming exam 1 time.

*/

# Write your MySQL query statement below
/*
    Intution / Basic algorithm
    -Basically in the below common table expression we have 
        we have to amp all the student s with all the subject in the Subjects table 
        so we did a CROSS JOIN like a cartesian product
        This is the result that we get

        CTE1
        | student_id | student_name | subject_name |
        | ---------- | ------------ | ------------ |
        | 1          | Alice        | Programming  |
        | 1          | Alice        | Physics      |
        | 1          | Alice        | Math         |
        | 2          | Bob          | Programming  |
        | 2          | Bob          | Physics      |
        | 2          | Bob          | Math         |
        | 13         | John         | Programming  |
        | 13         | John         | Physics      |
        | 13         | John         | Math         |
        | 6          | Alex         | Programming  |
        | 6          | Alex         | Physics      |
        | 6          | Alex         | Math         |

        This is the most crucil part of the following question
        in the following common table expression
        We have to group by the {student_id , subject_name}
        and the keep a cont of the fact that how many time in this 
        combination does each student_id or subject_name occures

        CTE2
        | student_id | subject_name | COUNT(student_id) |
        | ---------- | ------------ | ----------------- |
        | 1          | Math         | 3                 |
        | 1          | Physics      | 2                 |
        | 1          | Programming  | 1                 |
        | 2          | Programming  | 1                 |
        | 13         | Math         | 1                 |
        | 13         | Programming  | 1                 |
        | 13         | Physics      | 1                 |
        | 2          | Math         | 1                 |


        | student_id | student_name | subject_name | student_id | subject_name | COUNT(student_id) |
        | ---------- | ------------ | ------------ | ---------- | ------------ | ----------------- |
        | 1          | Alice        | Programming  | 1          | Programming  | 1                 |
        | 1          | Alice        | Physics      | 1          | Physics      | 2                 |
        | 1          | Alice        | Math         | 1          | Math         | 3                 |
        | 2          | Bob          | Programming  | 2          | Programming  | 1                 |
        | 2          | Bob          | Physics      | null       | null         | null              |
        | 2          | Bob          | Math         | 2          | Math         | 1                 |
        | 13         | John         | Programming  | 13         | Programming  | 1                 |
        | 13         | John         | Physics      | 13         | Physics      | 1                 |
        | 13         | John         | Math         | 13         | Math         | 1      ...

    Once once we have the following table we need to make a left outter join so that all the student,subject
    combination are been address and once we are doen with the same we have to 
        put in the join on 2 cols student_id and subject_name if both the match the includen in the query
    The case and order by are self explanatory in nature

*/



WITH CTE1 AS (
    SELECT * FROM Students CROSS JOIN Subjects
)
,
CTE2 AS (
    SELECT * ,COUNT(student_id) AS COUNTPEREXAM FROM Examinations 
    GROUP BY student_id,subject_name 
)

SELECT 
CTE1.student_id,
CTE1.student_name,
CTE1.subject_name,
CASE
    WHEN COUNTPEREXAM > 0 THEN COUNTPEREXAM
    ELSE 0
END AS attended_exams
FROM 
CTE1
LEFT JOIN
CTE2
ON 
CTE1.student_id=CTE2.student_id
AND
CTE1.subject_name=CTE2.subject_name
ORDER BY
CTE1.student_id,
CTE1.subject_name;

