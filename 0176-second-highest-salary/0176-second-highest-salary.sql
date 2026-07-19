# Write your MySQL query statement below
-- SELECT salary AS SecondHighestSalary FROM Employee ORDER BY salary DESC LIMIT 1 OFFSET 1;

select (
    select distinct salary
    from employee
    order by salary
    desc limit 1 offset 1
) as SecondHighestSalary;