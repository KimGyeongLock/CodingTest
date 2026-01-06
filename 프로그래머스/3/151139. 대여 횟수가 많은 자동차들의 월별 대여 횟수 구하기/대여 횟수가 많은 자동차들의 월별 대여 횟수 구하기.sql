-- 코드를 입력하세요
SELECT month(START_DATE) as MONTH, car_id, count(HISTORY_ID) as records
from CAR_RENTAL_COMPANY_RENTAL_HISTORY
where car_id in (
        select car_id
        from CAR_RENTAL_COMPANY_RENTAL_HISTORY
        where start_date >= '2022-08-01' and start_date <= '2022-10-31'
        group by car_id
        having count(*) >= 5
) and start_date >= '2022-08-01' and start_date <= '2022-10-31'
group by MONTH, car_id
order by month, car_id desc;
