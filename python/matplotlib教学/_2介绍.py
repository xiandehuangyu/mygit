import matplotlib.pyplot as plt
import numpy as np
#Figure跟踪所有子 Axes、一组“特殊”的 Artist（标题、图例、颜色条等），甚至嵌套的子图。
#自己根据要看的删去前面对应#号即可
#fig = plt.figure()             #空白图
#fig, ax = plt.subplots()       #子图
#fig, axs = plt.subplots(2, 2)   #2x2子图
#:一条子图在左边，两条子图在右边
#fig, axs = plt.subplot_mosaic([['left', 'right_top'],
#                               ['left', 'right_bottom']])
#Axes
#一个Axes是一个附属于 Figure 的 Artist，它包含用于绘制数据的区域，通常包括两个（或在 3D 情况下的三个）Axis 对象（请注意 Axes 和 Axis 之间的区别）
#它们提供刻度和刻度标签，为 Axes 中的数据提供刻度。
#每个Axes 也有一个标题（通过 set_title() 设置）
#一个x 轴标签（通过 set_xlabel() 设置），以及一个 y 轴标签（通过 set_ylabel() 设置）。
#Axes方法是配置图表大部分内容（添加数据、控制轴刻度和限制、添加标签等）的主要接口。
#Axis
#这些对象设置刻度和限制，并生成刻度（Axis 上的标记）和刻度标签（标记刻度的字符串）。
#刻度的位置由一个 Locator 对象决定，刻度标签字符串由一个 Formatter 格式化。
#正确的 Locator 和 Formatter 的组合可以对刻度位置和标签进行非常精细的控制
#Artist
#基本上,Figure上所有可见的都是Artist甚至是 Figure、Axes 和 Axis 对象）。
#这包括Text 对象,Line2D对象,collections对象,Patch对象等
#当Figure被渲染时，所有Artist都会绘制到画布上。
#大多数 Artist 都绑定到一个 Axes；这样的 Artist不能由多个 Axes 共享，也不能从一个 Axes 移动到另一个 Axes。
plt.show()