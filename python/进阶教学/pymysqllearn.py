#可以先去看看markdown文件里的mysql教程
from pymysql import Connection
#连接数据库
conn=Connection(host='localhost',port=3306,user='root',password='123456')
#创建游标
cursor=conn.cursor()
conn.select_db('test')#选择数据库
#执行sql语句,不需要;结尾
#非查询性语句
cursor.execute('create table user(id int,name varchar(50))')
#查询性语句
cursor.execute('select * from user')
#获取结果集
result:tuple=cursor.fetchall()#每个元素是一条数据，元组类型
for i in result:
    print(i)
#插入语句
cursor.execute('insert into user(id,name) values(1,"zhangsan")')
#提交事务
conn.commit()#不想每次都commit，可以设置自动提交，在创建连接时设置参数autocommit=True
#关闭链接
conn.close()
#以上就是pymysql的基本用法，基本就注意下查询和插入就行