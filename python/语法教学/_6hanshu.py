#函数
#基础语法
#定义函数
#def 函数名(参数1,参数2,...):
#    函数体
#    return 返回值
#可以无参数，也可以无返回值
#也可以写下函数说明，一般格式如下写在函数定义里下一行
"""
    :param 参数1: 参数1的说明
    :param 参数2: 参数2的说明
    :return: 返回值的说明
"""
#无返回值实际还是有返回值，只是返回None
#变量的作用域
#局部变量：函数内部定义的变量，只能在函数内部使用
#全局变量：函数外部定义的变量，可以在整个程序中使用
#如果在函数内部想修改全局变量，需要使用global关键字声明
#默认参数与关键字参数
#默认参数：函数定义时，给参数指定默认值，当调用函数时，如果不传入该参数，则使用默认值
#关键字参数：函数定义时，给参数指定参数名，当调用函数时，可以传入参数名来指定参数值
#无默认值参数必须在有默认值参数前面
def hello(year,old,name="world"):
    print(f"Hello, {name}! You are {old} years old in {year}.")
hello(2025,name="Alice",old=25)
hello(2024,29)
#位置参数：按函数定义的参数顺序传递，比如 hello(2025,25) 中，2025 匹配 year，25 匹配 old；
#关键字参数：通过参数名=值的形式传递，顺序可换，但必须放在位置参数之后
def fuck():
    print("fuck you!")
a=fuck()

print(type(a))

def greet(name):
    print(f"Hello, {name}!")
greet("Alice")

def add(x,y):
    """
    :param x: 第一个数
    :param y: 第二个数
    :return: 两个数的和
    """
    return x+y
print(add(3,5))

def erjinzhi(x):
    if x>1:
        erjinzhi(x//2)
        print(x%2,end="")
    else:
        print(x,end="")
erjinzhi(10)
#补充
#*args和**kwargs，建议后面再来看
#*args用于传递可变数量的位置参数，函数内部将其视为一个元组
"""
位置参数：按顺序传递、不用写参数名的参数
下面这个函数接收参数数量不定,故普通函数不行
def sum_numbers(*args):
    print("args的类型:", type(args))  # 查看args的类型(元组)
    total = 0
    # 遍历元组，累加所有传入的数字
    for num in args:
        total += num
    return total
"""
#**kwargs用于传递可变数据的关键字参数，函数内部将其视为一个字典
"""
关键字参数：参数名=值的形式
def print_info(**kwargs):
    print("kwargs的类型:", type(kwargs))  # 查看kwargs的类型(字典)
    # 遍历字典，打印所有信息
    for key, value in kwargs.items():
        print(f"{key}:{value}")

"""
