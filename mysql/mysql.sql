#文件名称:课堂练习
#文件描述:无
#编译环境:Linux
#作者相关:心文花雨 
#create database caozongkai;
#use caozongkai;
#create table test(id int,name varchar(10));
#insert into test values(1, 'caozongkai'); 
#insert into test values(2, 'zhangsan'); 
#select * from test;
#desc test;
#select * from test;
#create table tt12 (
#  name varchar(20) not null comment '姓名',
#  age tinyint unsigned default 0 comment '年龄',
#  sex char(2) default '男' comment '性别'
#);
#desc tt12;
#show create table tt12\G
#create table tt13 (
#  id int unsigned primary key comment '学号不能为空',
#  name varchar(20) not null
#);
#desc tt13;
#复合主键
#create table tt14(
#  id int unsigned,
#  course char(10) comment '课程代码',
#  score tinyint unsigned default 60 comment '成绩',
#  primary key(id, course) 
#);
#desc tt14;
create table tt15(
  id int unsigned primary key auto_increment,
  name varchar(10) not null default ''
);
insert into tt15(name) values('a');
insert into tt15(name) values('b');
select * from tt15;

