# Write your MySQL query statement below
SELECT p.firstname, p.lastname,a.city,a.state
from person p
left join address a
on p.personId = a.personId