#面向对象编程有3大特性:封装,继承,多态
#封装:把数据和操作数据的函数封装在一起,形成一个整体
#继承:子类继承父类的属性和方法,可以重写父类的方法,也可以添加新的方法
#多态:同一个方法,不同的对象,有不同的表现形式
#私有成员:无法被类成员使用,但可以被其它成员使用(以__开头)
class Person:
    def __init__(self, name, age, gender):
        self.name = name
        self.age = age
        self.__gender = gender
        self.aihao=None
    def set_aihao(self, aihao):
        aihao = input("请输入爱好:")
        self.aihao = aihao
        print("set_aihao:", self.aihao)
    def __reset_age(self, age):
        self.age = self.age + 1
        print("reset_age:", self.age)
    def __reset_name(self, name):
        self.name = input("请重新输入姓名:")
        print("reset_name:", self.name)
    def reset(self):
        self.__reset_name(self.name)
        self.__reset_age(self.age)
if __name__ == '__main__':
#上面就是一个Person类,它有name,age,gender,aihao属性,还有set_aihao方法,reset方法
    npc = Person('张三', 18, '男')
#npc.__reset_age(19)#报错,因为__reset_age是私有成员,无法被类成员使用
    npc.reset()
    print(npc.name, npc.age)
#print(npc.__gender)#报错,因为__gender是私有成员,无法被类成员使用
#下面为继承,为了减少重复,同时加新东西
#class 类名(父类名):此为单继承
class Student(Person):
    grade = None
    def __init__(self, name, age, gender, grade):
        # 方式1：调用父类的__init__，继承父类的属性
        super().__init__(name, age, gender)  # super()代表父类对象，无需写父类名，推荐用
        # 方式2：Person.__init__(self, name, age)  # 显式指定父类，多继承时需用
        self.grade = grade  # 子类新增属性
npc1 = Student('李四', 19, '男', '高三')
npc1.reset()  # 调用父类方法，重置姓名和年龄
pass#语法占位符,表示这里暂时没有代码,但语法上需要有代码,所以用pass占位,不然会报错
#class 类名(父类名1, 父类名2,...):此为多继承
class game:
    k:str='nihao'
    a='world' #type:str
    pass
class music:
    k:str='hello'
    pass
class phone(game, music):
    a:str='python'
    def m(self):
        print(f"a在父类中是{game.a},{super().a},在子类中是{self.a}")
    pass#相当于告诉程序我知道这里没写完,但你先别报错
#phone类继承了game和music类,可以使用game和music类的方法和属性
#即有了上面的功能
#注意:如果父类中有同名的方法,子类会优先调用第一个父类的方法,如果第一个父类没有这个方法,才会调用第二个父类的方法,以此类推
xiaomi = phone()
print(xiaomi.k)  # 输出nihao
#复写 对父类里不满意的方法进行重新定义,以满足自己的需求,这就是复写
#直接在子类中定义一个和父类同名的方法,就可以复写父类的方法了,见上a
print(xiaomi.a)  # 输出python,因为phone类复写了game类的a属性
#复写后要调用父类的话
#法一:super().成员变量或方法(self参数可省略)
#法二:父类名.成员变量或方法(self参数可省略)   多继承时需用
xiaomi.m()  # 输出a在父类中是world,world,在子类中是python
#类型注释,直接在变量名后面加上:类型,参数和变量都可以加上类型注释
#函数返回值的话加上->类型,比如def add(x:int, y:int)->int: return x+y
#容器的话,要在后面加上[元素类型],比如list[int],dict[str, int]
#字典要两个类型,元组要标记每个元素
#另一种写法是在末尾  #type:类型  这样可以让编辑器自动识别类型
