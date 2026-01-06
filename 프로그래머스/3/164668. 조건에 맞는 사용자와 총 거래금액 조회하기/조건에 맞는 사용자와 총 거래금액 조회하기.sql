-- 코드를 입력하세요
SELECT user_id, nickname, sum(price) as total_sales
from USED_GOODS_BOARD b
join USED_GOODS_USER u on b.WRITER_ID = u.user_id
where status = "DONE" 
group by user_id, nickname
having total_sales >= 700000
order by total_sales;

