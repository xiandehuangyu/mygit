#文件操作

# 打开文件
# open函数,open(name,mode,encoding)
# name:文件名
# mode:读写模式 r:读,w:写,a:追加(这三种最基础)rb:读二进制,wb:写二进制,ab:追加二进制
# 写和追加模式下,如果文件不存在,会自动创建文件
# 读模式下,如果文件不存在,会报错
# encoding:编码格式
f = open('./_14txt.txt',"r", encoding="UTF-8")
# read()方法:文件对象.read(num)
# num:读取的字节数,如果不指定,则读取全部内容
# 返回字符串
print(f.read(10))
print(f.read(10))
# 程序会记录读取的位置,下次再读取时,会从上次读取的位置开始读取
# readline()方法:文件对象.readline()
# 读取文件的一行内容,并返回字符串
# readlines()方法:文件对象.readlines()
# 读取文件的所有内容,并按行返回列表
# for line in f:
#     print(line)
# 每个line临时变量都记录了文件一行数据
# 关闭文件
# close()方法:文件对象.close()
f.close()
# with语句:执行完后,自动关闭文件
# with open(name,mode,encoding) as 文件对象:
# with open('./_14txt.txt',"r", encoding="UTF-8") as f:

#写入文件
f = open('./_14txt.txt',"w", encoding="UTF-8")
# write()方法:文件对象.write(string)
# string:要写入的字符串
f.write("hello world\n")
f.write("你好,世界\n")
# write还未真正写入文件,而是在程序的内存中,俗称缓冲区
f.flush() # 内容刷新,从而达到将缓存区的数据写入文件的目的
# 上面这样是为了避免频繁操作硬盘
f.close()

#追加文件
f = open('./_14txt.txt',"a", encoding="UTF-8")
f.write("hello again\n")
f.close()