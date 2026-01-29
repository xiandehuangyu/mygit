#python主要用空格来表示代码块的层级关系，建议每个层级使用4个空格缩进
#c主要用括号来表示代码块的层级关系
#判断语句if elif else与c类似
#循环语句for while 与c类似，不过没有do...while语句
#同样有break continue等控制循环的语句
#下面速通
#判断语句
#if 判断条件:
#(缩进)代码块1
#elif 判断条件2:
#(缩进)代码块2
#else:
#(缩进)代码块3
#循环语句
#for 变量 in 可迭代对象:
#(缩进)代码块
for i in range(10):
    print(i)
#range()函数用于生成一个整数序列，常用于for循环中
#range(结束值) 生成从0开始到结束值-1的整数序
#range(开始值, 结束值) 生成从开始值到结束值-1的整数序列
#range(开始值, 结束值, 步长) 生成从开始值
#区别于c语言的for循环，python可以用于遍历字符串、列表、元组、字典等各种可迭代对象
#如
for i in "hello":
    print(i)
for i in [1,2,3]:
    print(i)
for i in (4,5,6):
    print(i)
for k in {"a":1,"b":2}:
    print(k) #默认遍历字典的key
#while 判断条件:
#(缩进)代码块
#break 跳出当前循环
#continue 跳过本次循环，进行下一次循环
#如：
# while True:
#     s = input("输入exit退出循环：")
#     if s == "exit":
#         break
#     else:
#         continue