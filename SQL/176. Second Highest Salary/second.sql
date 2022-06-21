/*
Question is finding second highest salary

Main idea:
if there are less than 2 distinct salaries, "second highest" can't be exist; then answer is null.
Else case:
From highest 2 salaries (can be found by using "order by" and "limit" keywords)
Select the salary which is not equal to the highest salary
*/

SELECT IF((SELECT COUNT(DISTINCT salary) FROM Employee) < 2, null,
(SELECT salary
FROM
(
SELECT DISTINCT salary 
FROM Employee
ORDER BY salary DESC
LIMIT 2
) AS HighestTwo
WHERE
salary != (SELECT MAX(salary) FROM Employee))
  ) AS SecondHighestSalary;
