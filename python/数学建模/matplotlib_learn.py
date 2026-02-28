#https://matplotlib.org/stable/plot_types/index.html
import matplotlib.pyplot as plt
import numpy as np
#解决中文显示问题
#from matplotlib.pylab import mpl
#mpl.rcParams['font.sans-serif']=['SimHei']
#用来正常显示中文标签，因为默认字体不支持中文
#mpl.rcParams['axes.unicode_minus']=False
#解决负号显示问题，默认负号显示正常
x=np.linspace(0,10,100)#开始值，结束值，生成的元素个数
#print(x)
print(type(x))
y=np.sin(x)
#折线图
#元素个数改少一点能看到效果
plt.plot(x,y,ls='--',label='model')#加参数可以控制线条颜色,线条宽度,线型等，如c='r',lw=2,ls='--'
#如果要加标签说明，加参数label='name'，然后加一句plt.legend()在plt.show()前面才能看到
plt.title('y=sin(x)')
plt.xlabel('x')
plt.ylabel('y')
#plt.show()
x2=np.linspace(0,10,10)
y2=np.sin(x2)
#散点图
plt.scatter(x2,y2,c='r',s=50,marker='*',label='test')#加参数可以控制点形状之类的,如s=50,c='r',marker='*',大小,颜色,形状等
#plt.title('y=sin(x)')
#plt.xlabel('x')
#plt.ylabel('y')
plt.legend()
plt.show()