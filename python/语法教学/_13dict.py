#字典字面量 {key:value, key:value, ... ,key:value}
#定义字典变量 变量名 = {key:value, key:value, ... ,key:value}
#定义空字典变量 变量名 = {}或变量名 = dict()
#字典的key必须是不可变对象，如字符串、数字、元组等，不能是可变对象，如列表、字典等。
#字典的value可以是任意对象。
#字典的key是唯一的，不能重复。重复的key会覆盖前面的key。
mydict = {1:'nihao',2:'hello',3:'world',1:'hello','hl':'python'}
print(mydict)
#不能通过下标索引,但能通过key索引
#语法：字典名[key]
print(mydict[1])
print(mydict['hl'])
#修改字典元素
#字典名[key] = value 注:若不存在则为添加
#字典名.pop(key) 删除key和对应的value并返回value
k=mydict.pop(2)
print(k)
print(mydict)
#字典名.clear() 清空字典
#字典名.keys() 返回字典所有key组成的列表
mydict[2]='nihao'
mydict[4]='hello'
print(mydict.keys())
#字典名.values() 返回字典所有value组成的列表
print(mydict.values())
#字典名.items() 返回字典所有key-value组成的列表
#遍历字典,下面两种方式是一样的
#for key in 字典名:
#for key in 字典名.keys():
for key in mydict:
    print(mydict[key])
#len(字典名) 返回字典元素个数 略