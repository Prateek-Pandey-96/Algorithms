# http://bit.ly/3gKC7Om
# select max(time_stamp) as last_stamp, user_id FROM logins where 
# extract(year from time_stamp) = '2020' group by user_id


# http://bit.ly/3VkTQea
# select a.sale_date, coalesce(apples, 0)-coalesce(oranges, 0) as diff 
# from
# (select sold_num as apples, sale_date from Sales where fruit='apples')a
# left join
# (select sold_num as oranges, sale_date from Sales where fruit='oranges')b
# on a.sale_date = b.sale_date



# http://bit.ly/3VhuGNC
# select 'Low Salary' as category, count(*) as accounts_count
# from accounts where income < 20000
# union
# select 'Average Salary' as category, count(*) as accounts_count
# from accounts where income >= 20000 and income <= 50000
# union
# select 'High Salary' as category, count(*) as accounts_count
# from accounts where income > 50000
