#package,包,相当于一个文件夹,里面有多个模块文件,可以被其他程序引用
#需要包含__init__.py文件,否则python不会认为这个文件夹是一个包
#可以在__init__.py里定义一些对象,如__all__变量,用于控制导入的模块

#导入包
#import 包名.模块名
#from 包名 import 模块名
#from 包名.模块名 import 函数名

#安装第三方包
#pip install 包名
#稍微举下好用的第三方包
#科学计算常用numpy,数据分析常用pandas,图形可视化matplotlib,pyecharts
#大数据计算pyspark,人工智能tensorflow,大数据计算pyspark,apache-flink
#下载慢的话,可以用魔法,或者pip install -i https://pypi.tuna.tsinghua.edu.cn/simple/ 包名