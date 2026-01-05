-- 코드를 입력하세요
SELECT car_id, 
       if(max(start_date <= '2022-10-16' and end_date >= '2022-10-16') = 1, 
          '대여중', 
          '대여 가능'
         ) as AVAILABILITY
from CAR_RENTAL_COMPANY_RENTAL_HISTORY
group by car_id
order by car_id desc;