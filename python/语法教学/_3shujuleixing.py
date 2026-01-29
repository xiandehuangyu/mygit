# type() 查看数据类型
# 下面只初步简单说明，对应函数后续介绍
# 暂时可以不管int float str bool以外的
a = 10 #int
b = 3.14 #float
c = "hello" #str 单引号，双引号，三引号均可
d = [1, 2, 3] #list 方括号
e = (1, 2, 3) #tuple 小括号
f = {1, 2, 3} #set 花括号，但元素不是键值对
g = {"a": 1, "b": 2} #dict 花括号
h = True #bool
i = None #NoneType
j = complex(1, 2) #complex 复数
print(type(a))
print(type(b))
print(type(c))
print(type(d))
print(type(e))
print(type(f))
print(type(g))
print(type(h))
print(type(i))
print(type(j))
"""
int()将其他类型转换为整数
int("123")      # 输出: 123
int(123.45)     # 输出: 123
int("1010", 2)  # 输出: 10 (二进制转十进制)
float()将其他类型转换为浮点数
float("3.14")   # 输出: 3.14
float(123)      # 输出: 123.0
str()将其他类型转换为字符串
str(123)        # 输出: '123'
str(3.14)       # 输出: '3.14'
list()将其他类型转换为列表
list((1, 2, 3))  # 输出: [1, 2, 3]
list("abc")      # 输出: ['a', 'b', 'c']
tuple()将其他类型转换为元组
tuple([1, 2, 3]) # 输出: (1, 2, 3)
tuple("abc")     # 输出: ('a', 'b', 'c')
set()将其他类型转换为集合
set([1, 2, 3])   # 输出: {1, 2, 3}
set("abc")       # 输出: {'a', 'b', 'c'}
dict()将其他类型转换为字典
dict([("a", 1), ("b", 2)]) # 输出: {'a': 1, 'b': 2}
bool()将其他类型转换为布尔值 非零数字和非空对象为True
bool(1)          # 输出: True
bool(0)          # 输出: False
bool("")         # 输出: False
bool("abc")      # 输出: True
complex()将其他类型转换为复数
complex(3, 4)  # 输出: (3+4j)
complex(5)     # 输出: (5+0j)
"""