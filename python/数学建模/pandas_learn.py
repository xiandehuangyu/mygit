#pandas: https://pypandas.cn/docs/
import pandas as pd
import numpy as np
#excel与字典相对应
data={'姓名':['张三','李四','王五'],'年龄':[20,25,30],'薪资':[5000,6000,7000]}
datadf=pd.DataFrame(data)
print(datadf)
df=pd.read_excel("python/数学建模/sales_test.xlsx",'销售数据',engine='openpyxl')
#前者是文件名，后者是表单名,表单名可以省略，一般excel默认是Sheet1，我这里时多表单，销售数据和用户信息
#最后是打开excel文件的引擎，这里使用openpyxl,需要安装openpyxl库
print(df.head())#查看前五行数据,默认是5,传入数字可以查看指定行数
print(df.tail())#查看后五行数据，同上
print(df.info())#查看数据信息，包括列名、数据类型、非空值个数、内存占用等
#缺失值处理
df=df.dropna()#删除缺失值
df['销量']=df['销量'].astype(float)#将销量列的数据类型转换为float
print(df.info())#查看数据信息，销量列的数据类型已经变为float
#以上为数据处理第一步，一般转换用得少
#数据选择过滤(与numpy中操作差不多)
print(df['是否包邮']== 1)
print(df[df['是否包邮']== 1])#筛选出是否包邮的行
df1=df[(df['是否包邮']== 1)]
print(df1.info())
#计算直接调numpy
lb=df['销量'].mean()-3*df['销量'].std()
ub=df['销量'].mean()+3*df['销量'].std()#常用正太分布的上下限，3倍标准差
print(df[(df['销量']>lb) & (df['销量']<ub)])#excel找ai生成的，数据比较少，所以这里都符合
#以上就是数学建模常用的数据处理方法，更多方法请参考官方文档