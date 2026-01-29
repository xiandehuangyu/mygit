# 这是单行注释
"""
这是多行注释
"""
# 基础print
print("Hello, world!")
print('Hello, world!')#单双引号均可(下同)
print('''Hello, 
      world!''')#使用三个引号可以直接多行输入

a = 'hello'
b = 'world'
c=2
print(a +' ' + b,end=' ')#end参数用于指定print结尾的字符，默认是换行符
print(a,b) # ,号用来分隔多个参数，默认输出空格
print(a,b,sep='-')#sep参数用于指定多个参数之间的分隔符，默认是空格
print(a*c)#字符串重复输出

print(f"{a}{b: ^10}!{c:.2f}")
#f-string格式化字符串,将想输出的放在{}中即可
#^表示居中对齐，>表示右对齐，<表示左对齐，10表示宽度为10，:表示格式化符

print("{0}{1:^10}!".format(a,b))
#str.format格式化字符串,用{}作为占位符，按顺序或指定位置填充变量
#0表示第一个变量，1表示第二个变量

print("{a}{b:^10}!".format(a=b,b=a))
#指定变量名作为关键字参数

print("%5.2f %-10s %10s" % (c, a, b))#旧式格式化字符串,类c语言的printf函数
# %5.2f表示输出浮点数，5表示总宽度为5，小数点后保留2位，-表示左对齐

# 补充，要在字符串里输出引号，可以用转义字符\，或者用另一种引号包裹
print("He said, \"Hello!\"")
print('He said, "Hello!"')