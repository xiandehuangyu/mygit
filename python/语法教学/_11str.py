#字符串同样不可修改
#字符串定义与索引操作略
text = "hello world, how are you?"
#字符串.index(字符串)方法
a=text.index('how')
print(a)
#字符串.find(字符串)方法
b=text.find('are')
print(b)
#index()方法和find()方法的区别：
#index()方法如果找不到子串，会抛出ValueError异常；
#find()方法如果找不到子串，会返回-1。
#字符串.count(字符串)方法
c=text.count('l')
print(c)
#字符串.replace(子串, 新串)方法,将字符串中的子串替换为另一个子串,并返回替换后的字符串
#注:replace()方法不会改变原字符串,而是返回一个新的字符串
d=text.replace('world', 'Python')
print(d)
print(text)
#字符串.split(分割符字符串)方法,空的话默认为空格
e=text.split()
print(e)
#字符串='分割符'.join(列表)方法,将列表中的元素用分割符连接成一个字符串
f=','.join(e)
print(f)
#字符串.strip()方法,去掉字符串两端的空格
text='  hello world  '
print(text)
g=text.strip()
print(g)
#字符串.strip(字符)方法,去掉字符串两端的指定字符(多个字符里面用字符串表示,不用管顺序)
text='hi,hello,world!ihh'
print(text.strip('i,h'))
#len()函数,返回字符串的长度,len(字符串)