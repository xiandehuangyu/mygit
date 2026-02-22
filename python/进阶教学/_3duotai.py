#本来想融在一起的,主要感觉分开的话,封装太短了,结果继承写的又有点多
#多态:指完成某个行为,不同对象有不同状态
class Animal:
    def speak(self):
        pass
class Dog(Animal):
    def speak(self):
        print("汪汪汪!")
class Cat(Animal):
    def speak(self):
        print("喵喵喵!")
class Human(Animal):
    def speak(self):
        print("嘤嘤嘤!")
def animal_speak(animal:Animal):
    animal.speak()
dog = Dog()
cat = Cat()
human = Human()
animal_speak(dog)
animal_speak(cat)
animal_speak(human)
#原理:本来要用父类的方法,但传入的是子类,而子类里又重写了父类的方法,所以就调用了子类的方法
#父类里写pass也叫空实现,这里也可以叫Animal为抽象类(接口),因为其含了抽象方法(空实现的方法)
#speak为抽象方法,需要在子类里重写,否则就会报错,因为抽象方法没有实现,无法被调用