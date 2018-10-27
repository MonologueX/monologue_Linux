#文件名称:练习
#文件描述:无
#编译环境:Linux
#作者相关:心文花雨
#create database caihao;
#use caihao;
#create table test(id int, name varchar(10), password varchar(12));
#insert into test values (1, 'caihao', '123456');
#insert into test values (2, 'zhangsan', '456789');
#select * from test;
#desc test;
#create table tt1(
#  id int primary key auto_increment,
#  name varchar(12) not null default ''
#);
#create table tt2(
#  id int unique,
#  name varchar(10)
#);
#insert into tt2 values(1, 'test1'),(2,'test2');
#insert into tt2(id) values(2);
#insert into tt2(name) values('test3');
#insert into tt2(name) values('test4');
#create table myclass(
#  id int primary key,
#  name varchar(10) not null comment '班级名称'
#);
#create table student(
#  id int primary key comment '学生id',
#  name varchar(20) not null comment '学生姓名',
#  class_id int,
#  foreign key(class_id) references myclass(id)
#);
#insert into myclass values (1, 'class_1'),(2, 'class_2');
#insert into student values (10, 'test1', 1),(20, 'test_2', 2);
#insert into myclass values (30, 'class_1', 3);
#create table goods(
#  id int primary key auto_increment,
#  name varchar(20) not null default '',
#  price decimal(4,2) not null default 0.0
#);
#insert into goods values(100, '好吃点', 10.0);
#insert into goods values('100', '方便面', 1.0);
#insert into goods values(100, '炒面', 9.0)
#  on duplicate key update goods name = '炒面',price = 9.1;

