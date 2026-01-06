select category, sum(sales) as total_sales
from book b
join book_sales s on b.book_id = s.book_id
where SALES_DATE >= '2022-01-01' and SALES_DATE < '2022-02-01'
group by category
order by category;
