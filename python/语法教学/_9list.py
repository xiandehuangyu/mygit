#字面量 [元素1, 元素2, 元素3,...]
#列表:可封装多个,不同类型,可修改的元素
#定义列表 变量名 = [元素1, 元素2, 元素3,...]
#定义空列表 变量名 = [] 或 变量名 = list()
#列表元素的类型可以不同，列表中的元素可以是任意类型，可以是数字、字符串、元组、列表、字典等。
#列表的索引从0开始，可以用负数索引从后往前。
#列表的长度是列表中元素的个数。
#列表的操作：
my_list = [[1,1,4],5,1,4,"nihao",1,True]
#1. 索引：通过索引可以访问列表中的元素，索引从0开始，可以用负数索引从后往前。
print(my_list[0]) #输出[1, 1, 4]
print(my_list[-1]) #输出True
print(my_list[1:5]) #输出[5, 1, 4, "nihao"]
#与range一样,到[开始索引:结束索引:步长]
print(my_list[4][1]) #输出i
print(my_list)
#也可以通过索引重新赋值来修改元素
#2. 查找：通过 列表.index(索引) 方法可以查找元素的索引，通过 列表.count(元素) 方法可以统计元素的个数。
print(my_list.index(1)) #输出2,返回第一个1的索引
# print(my_list.index(2)) 报错，元素不存在
print(my_list.count(1)) #输出3
#3. 追加：通过 列表.append(元素) 方法可以向列表中添加元素。 列表.extend(容器) 方法可以向列表中添加多个元素。
# append(元素),在列表末尾添加元素
my_list.append('world')
# extend(容器)，将容器中的元素逐个取出添加到列表末尾
my_list.extend('hello')
print(my_list)
#4. 插入：通过 列表.insert(索引, 元素) 方法可以向列表中插入元素
my_list = [[1,1,4],5,1,4,"nihao",1,True]
# insert(索引, 元素),在索引位置插入元素
my_list.insert(2, "hello")
print(my_list)
#5. 删除：通过 列表.remove(元素) 方法可以删除列表中指定元素
my_list.remove('hello')
print(my_list)
# 通过 列表.pop()方法可以删除列表中最后一个元素，并返回该元素。
a=my_list.pop()
print(a)
print(my_list)
# 通过 列表.pop(下标)和del 列表[下标]函数可以删除列表中指定位置的元素
my_list.pop(0)
print(my_list)
del my_list[0]
print(my_list)
# 通过 列表.clear()方法可以清空列表。
my_list.clear()
print(my_list)
#6. 排序：通过 列表.sort() 方法可以对列表进行排序，reverse=True可以反转排序顺序。
my_list = [3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5]
my_list.sort()
print(my_list)
my_list.sort(reverse=True)
print(my_list)
#7. 遍历：通过for循环可以遍历列表中的元素。while循环用下标方法与c类似,不做介绍
#for i in my_list:
#    print(i)
#8. 成员资格：通过in关键字可以判断元素是否在列表中。
print(1 in my_list) #输出True
#9. 长度：通过len()函数可以获取列表的长度。
print(len(my_list)) #输出11