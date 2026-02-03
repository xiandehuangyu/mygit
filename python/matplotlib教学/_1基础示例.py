import matplotlib.pyplot as plt #导入matplotlib库并简写为plt
import numpy as np #导入numpy库并简写为np
# matplotlib是一个python的2D绘图库，它提供了大量的图表类型，包括折线图、散点图、直方图、饼图等。
# numpy是一个python的科学计算库，它提供了多种数值计算函数，包括线性代数、傅里叶变换、随机数生成等。
#fig = plt.figure() # 创建一个空白的图表
#plt.show() # 显示图表
fig, ax = plt.subplots() # 创建一个空白的图表，并将其与一个坐标轴ax绑定
#ax.plot([1,2,3,4],[1,4,2,3])
#plot函数用于绘制折线图，第一个参数为横坐标，第二个参数为纵坐标。
ax.scatter([1,2,3,4],[1,4,2,3])
#scatter函数用于绘制散点图，第一个参数为横坐标，第二个参数为纵坐标。
plt.show() # 显示图表