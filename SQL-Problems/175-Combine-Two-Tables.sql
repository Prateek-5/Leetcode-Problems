# Write your MySQL query statement below

/*
    Intution / Basic Algorithm
    Write a solution to report the first name, last name, city, and state of each person in the Person table.
    If the address of a personId is not present in the Address table, report null instead.

    As we can see in the question we need to include all the records of the Person table be it present in the Address table or not
        Inner join -> Eliminated (only the match records is not expected)
        Outer join -> Eliminated (all the record of the address table is not required)
        Right join -> Eliminated(all the records ofthe preson table would be present but the records of the Person will not be included)
        Left join -> (condsidering the Person table as the left table all the records of the preson table would be included and
            the the records that are not present in the address able would automatically get null value in the address table columns)
        
    Why do we write p.first name
        See when we perform join operation we have the access of all the the columns be it presonId from Person or personId from Address
        to overcome the ambiguity we use this notation
    Person p ->this is used to use p as a short form for Person table

*/
SELECT 
    p.firstName,
    p.lastName,
    a.city,
    a.state
FROM
    Person  p
LEFT JOIN
    Address a
ON p.personId=a.personId;