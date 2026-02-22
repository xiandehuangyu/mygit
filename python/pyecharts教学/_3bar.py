#基础的柱状图构建和折线图差不多
from pyecharts.charts import Bar,Timeline
from pyecharts.options import *
from pyecharts.globals import ThemeType
"""
里面就是最基础的了
bar = Bar()
bar.add_xaxis(['中国', '美国', '英国', '法国', '德国'])
bar.add_yaxis('GDP', [200, 200, 150, 120, 180], color="#42416C",label_opts=LabelOpts(position="right"))
bar.reversal_axis()#翻转坐标轴,变成水平柱状图
bar.render()
"""
bar1=Bar()
bar1.add_xaxis(['中国', '美国', '英国'])
bar1.add_yaxis('GDP', [200, 200, 150],label_opts=LabelOpts(position="right"))
bar1.reversal_axis()
bar2=Bar()
bar2.add_xaxis(['中国', '美国', '英国'])
bar2.add_yaxis('GDP', [300,230,160],label_opts=LabelOpts(position="right"))
bar2.reversal_axis()
bar3=Bar()
bar3.add_xaxis(['中国', '美国', '英国'])
bar3.add_yaxis('GDP', [400,280,220],label_opts=LabelOpts(position="right"))
bar3.reversal_axis()
#上面都是准备数据
#下面是构建时间轴
timeline = Timeline({'theme':ThemeType.LIGHT})
#传入参数设置主题,没导入ThemeType就直接空就行,这里就是控制颜色
timeline.add(bar1, "2024年GDP")
timeline.add(bar2, "2025年GDP")
timeline.add(bar3, "2026年GDP")
#设置自动播放
timeline.add_schema(
    is_auto_play=True,
    play_interval=1000,  # 间隔时间，单位为毫秒
    is_loop_play=True,  # 是否循环播放
    is_timeline_show=True # 是否显示时间轴
)
timeline.render()
"""
想做成某些视频里中国觉醒的效果的话
自己准备数据,然后每次用各种方法整理出x轴和y轴数据,每次构建一个Bar对象,最后把这些对象添加到Timeline里就行了
对列表排序,使用sort方法
列表.sort(key=选择排序依据的函数, reverse=True|False)
如a=[("中国", 200), ("美国", 200), ("英国", 150)]
依据元组的第2个元素排序,a.sort(key=lambda x:x[1], reverse=True)
#lambda x:x[1]表示以元组的第2个元素为排序依据,reverse=True表示降序排序
"""