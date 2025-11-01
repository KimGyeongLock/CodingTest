-- 코드를 작성해주세요
select i.item_id, item_name, rarity
from item_info as i
join item_tree as t on i.item_id = t.item_id
where parent_item_id in (select item_id 
                        from item_info
                        where rarity = 'rare')
order by i.item_id desc;