# Write your MySQL query statement below
SELECT Employees.employee_id FROM Employees
LEFT JOIN Salaries ON Employees.employee_id=Salaries.employee_id
WHERE salary is NULL
UNION
SELECT Salaries.employee_id FROM Employees
RIGHT JOIN Salaries ON Employees.employee_id = Salaries.employee_id
WHERE name IS NULL

order by employee_id ASC