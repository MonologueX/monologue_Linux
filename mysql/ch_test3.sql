#文件名称:
#文件描述:
#编译环境:Linux
#作者相关:心文花雨 
#create database ch_test2;
#use ch_test2;
#create table test(id int, name varchar(10), qq varchar(12));
#har(10),nsert into test values (1, 'test1', '412342');
#dess varchar(20), test;
#select varchar(15) unique, * from test;
#create database goods;
use goods;
#create table goods(goods_id int unsigned primary key auto_increment, 
#  goods_name varchar(10) not null default '',
#  unitprice float(8, 2) not null default 0.0,
#  category smallint not null default 0,
#  provider varchar(100) not null default ''
#);

#create table customer(customer_id int unsigned primary key auto_increment,
#  name varchar(10),
#  address varchar(20),
#  emali varchar(15) unique,
#  sex enum('0', '1') not null default '0',
#  card_id varchar(30)
#);

create table purchase(order_id varchar(30) not null primary key,
  customer_id int unsigned,
  goods_id int unsigned,
  nums int not null default 0,
  foreign key(customer_id) references customer(customer_id),
  foreign key(customer_id) references goods(goods_id),
);
