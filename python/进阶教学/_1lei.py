#恭喜你,找到对象了! :)
#什么叫你真的有对象 :(
#没有对象的话,我们就自己弄个一个
#先设计一个类
#类相当于一种数据类型,为了针对解决实际问题而创建,可能相当于c的结构体?
#class 类名:
#    类的属性(即定义在类里的变量,也叫成员变量)
#    
#    类的行为(即定义在类里的函数,也叫成员方法)
#创建类对象
#对象名 = 类名()
#给对象属性赋值
#对象名.属性名 = 值
#定义成员方法
#def 方法名(self,参数):
#self是关键字,必须有,表示类对象本身,使用类对象调用方法时,会自动传入
#方法内部要访问类的成员变量,就必须使用self
#调用对象方法
#对象名.方法名(参数)
class Student:
    name = None
    age = None
    gender = None
    def jieshao(self,times):
        for i in range(times):
            print(f"大家好,我是{self.name},今年{self.age}岁了")
    def __init__(self,name,age,gender):
#__init__方法是一个特殊的方法,叫做构造方法,在创建对象时,会自动启动这个方法,传入的参数会自动传给这个方法
        self.name = name
        self.age = age
        self.gender = gender
#self.name和self.age就是访问了类的成员变量,如果直接用name和age就会报错,因为方法内部没有定义这两个变量
"""
#创建一个对象
stu1 = Student()
#给对象属性赋值
stu1.name = "张三"
stu1.age = 20
stu1.gender = "男"
"""
stu1 = Student("张三",20,"男")
#没有__init__方法的话,就只能创建空对象,然后再给属性赋值即三引号里面的多行
#调用对象方法
stu1.jieshao(3)
#面向对象编程:设计类,基于类,创建对象,由对象做具体工作
#类似于__init__这种内置的类方法,统称为魔术方法,下面是比较常用的

#__str__字符串方法
print(stu1)#输出的是内存地址
print(str(stu1))#输出的是对象内容,跟上面一样
#但如果在类定义里添加
#def __str__(self):
#    return f"学生{self.name},年龄{self.age},性别{self.gender}"
#就可以直接输出对象内容了,相当于直接把对象转换成字符串了,所以输出就变成了学生张三,年龄20,性别男
#个人理解是定义打印对象时的格式,如果不定义就默认输出内存地址了

#__lt__小于大于符号比较
#要直接比较对象的大小,必须先定义
#def __lt__(self,other):
#    return self.age < other.age #age是数字,所以可以直接比较

#__le__小于等于大于等于符号比较
#def __le__(self,other):
#    return self.age <= other.age

#__eq__等于符号比较
#def __eq__(self,other):
#    return self.age == other.age