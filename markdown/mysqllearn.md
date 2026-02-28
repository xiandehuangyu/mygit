# MySQL 学习笔记
MySQL主要用来存储和管理大量的关系型数据。
功能主要划分为四大类：
- 数据定义（Data Definition Language，DDL）：用于定义数据库对象，如数据库、表、列、索引等。
- 数据操纵（Data Manipulation Language，DML）：用于操作数据库对象，如插入、删除、更新数据。
- 数据控制（Data Control Language，DCL）：用于控制数据库的访问权限和安全。
- 数据查询（Data Query Language，DQL）：用于查询数据库中的数据和计算数据。
## 目录
- [MySQL 学习笔记](#mysql-学习笔记)
  - [目录](#目录)
  - [语法特征](#语法特征)
  - [数据定义](#数据定义)
    - [数据库操作](#数据库操作)
    - [表操作](#表操作)
  - [数据操纵](#数据操纵)
  - [数据控制](#数据控制)
  - [数据查询](#数据查询)
  - [补充语法语句](#补充语法语句)
## 语法特征
MySQL不区分大小写，但在SQL语句中，关键字必须使用大写字母。
可以单行和多行书写，最后以分号结尾。
MySQL的注释：
- 单行注释：以 `--` 开头，然后接一个空格，直到行尾。或者 `#` 开头，这种空格随意，建议接一个养成习惯。
- 多行注释：以 `/*` 开头，以 `*/` 结尾。
## 数据定义
### 数据库操作
- 查看数据库：`SHOW DATABASES;`
- 使用数据库：`USE 数据库名;`
- 创建数据库：`CREATE DATABASE 数据库名 [CHARSET UTF8];`
中括号内的选项是可选的，`CHARSET UTF8` 表示字符集为 UTF8。
- 删除数据库：`DROP DATABASE 数据库名;`
- 查看当前使用的数据库：`SELECT DATABASE();`
### 表操作
- 查看所有表：`SHOW TABLES;`
- 创建表：`CREATE TABLE 表名 (列名 类型, 列名 类型, 列名 类型);`
类型有：int整型 varchar(n数字 限制长度)文本 date日期类型 float浮点数 timestamp时间戳类型。
- 删除表：`DROP TABLE 表名;`或`DROP TABLE IF EXISTS 表名;`
## 数据操纵
- 插入数据: `INSERT INTO 表名[(列名1, 列名2,...)]VALUES(值1, 值2,...)[, (值1, 值2,...) ,...];`
- 删除数据: `DELETE FROM 表名[WHERE 条件判断];`
条件判断: 列 操作符 值
操作符: =, >, <, >=, <=, !=等，如 `age > 20`
- 更新数据: `UPDATE 表名 SET 列=值[,列名=值,..][WHERE 条件判断];`
[补充语法语句](#补充语法语句)
## 数据控制
———待补充———（现学现写的，这个我看的视频里没教，可能是因为这个用得少）
## 数据查询
- 查询数据: `SELECT 字段列表|* FROM 表[WHERE 条件判断]`
### 分组聚合
用于对数据进行分组和聚合，从而来完成一些需求，如求总和、平均值、最大值、最小值等。
- 语法: `SELECT 字段|聚合函数 FROM 表[WHERE 条件判断] GROUP BY 列;`
聚合函数: AVG(列)求平均, COUNT(列|*)求数量, MAX(列)求最大值, MIN(列)求最小值, SUM(列)求总和 等。
例: `SELECT gender, AVG(age),MAX(age),MIN(age),COUNT(*) FROM table GROUP BY gender;`
### 排序
- 语法: `SELECT 字段|聚合函数 FROM 表[WHERE 条件判断] GROUP BY 列 ORDER BY 列 [ASC|DESC];`
ASC: 升序，DESC: 降序。不写默认升序。
例: `SELECT * FROM table WHERT age > 20 ORDER BY age DESC;`
### 结果分页限制
- 语法:在最后加上`LIMIT [m,]n;`n表示数量，m表示偏移量，默认m=0。
例: `SELECT * FROM table LIMIT 5,10;`表示从第6条开始，取10条。

## 补充语法语句
CASE 语句: `CASE 表达式 WHEN 值1 THEN 结果1 WHEN 值2 THEN 结果2... [ELSE 其他结果] END;`
适用于多条件判断。如想修改指定两个id的名字, 可以用如下语句：
`UPDATE table_name SET name=CASE id WHEN 1 THEN '张三' WHEN 2 THEN '李四' ELSE name END WHERE id IN (1, 2);`
WHERE避免全盘扫描,如果去掉WHERE条件,那么ELSE不能省略，因为没ELSE的话，如果没匹配的会返回NULL。
IF 语句: `IF(条件判断, 结果1, 结果2)`
相当于适用于二选一的CASE语句。