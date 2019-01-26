-- 创建表
create table test(
    id int, 
    name varchar(10), 
    sex varchar(10),
    qq varchar(12)
);
 
-- 显示表的结构
desc test;
 
-- 插入数据
insert into test values (1, "温婷歌", "女", "31984892");
insert into test values (2, "冷千绝", "男", "36546562");
insert into test values (3, "许艺笙", "女", "45263272");
insert into test values (4, "秦亦然", "男", "98234612");

-- 查看表中数据
select * from test;
 
-- 修改某一字段的属性, 属性要重新定义
alter table test change sex gender varchar(60);
desc test;

-- 删除某一字段
alter table test drop qq;
desc test;
select * from test;

-- 修改表的名字
alter table test rename to mytest;
desc test;

-- 删除表
drop table mytest;
show tables;
