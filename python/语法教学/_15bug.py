#处理异常(bug)
#遇到bug,程序一般有两种情况
# 1.程序因为一个bug停止运行
# 2.程序提醒bug,但继续运行

# 捕获异常
# 作用是假设程序在某处出错,做好提前准备,当真的出现异常时有后续手段
#try:
    # 可能出错的代码
#except:
    # 出现异常时执行的代码
#如
try:
    f=open('file.txt','r')
except:
    print('文件不存在,打开失败')
    #f=open('file.txt','w')#去掉#号运行会创建文件
else:#else语句在try语句没有发生异常时执行,下面的例子也可以用,就不多重复写了
    print('文件打开成功')
    f.close()
finally:#finally语句无论是否出现异常都会执行,下面就不重复写了
    print('程序结束')
# 捕获指定异常
try:
    print(a)#type: ignore[name-defined]
except NameError as e:
    print('变量a未定义')
    print(e)
# 捕获多个异常,将要捕获的异常用元组形式
# 不对应就不能捕获
try:
    print(1/0)
except (ZeroDivisionError,NameError) as e:
    print('除数不能为0')
    print(e)
# 捕获所有异常,用except Exception:
try:
    print(1/0)
except Exception as e:
    print('出现异常')
    print(e)