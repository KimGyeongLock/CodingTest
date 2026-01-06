-- 코드를 작성해주세요
select count(*) as fish_count, max(length) max_length, fish_type
from FISH_INFO
group by fish_type
having avg(length) >= 33
order by fish_type;