"""
pyecharts主要用于数据可视化,会生成html文件,在浏览器中打开即可看到图表,便于分享和交流。
感觉学的话主要还是自己去看文档,教学只包含折线,地图,柱状图
基本流程就是 构建对象,准备数据,添加数据,设置全局配置,生成图表
https://pyecharts.org/#/zh-cn/intro
https://gallery.pyecharts.org/#/README

安装: pip install pyecharts
"""
# 导入Line类,创建一个折线图对象
from pyecharts.charts import Line
line = Line()
# 添加x轴数据
line.add_xaxis(['周一', '周二', '周三', '周四', '周五', '周六', '周日'])
# 添加y轴数据
line.add_yaxis('收入',[1,1,4,5,1,4,2],color="#42416C")
# 全局配置,主要通过set_global_opts方法,可以设置标题、工具箱、数据缩放等全局配置项
# 系列配置,LableOpts、LineStyleOpts等方法,可以设置系列的标签、线条样式等配置项
# 如下面这个可以使数字不显示
#line.add_yaxis('收入', [1, 1, 4, 5, 1, 4, 2],label_opts=opts.LabelOpts(is_show=False))
# 鼠标放在方法上,会显示参数说明,也可以在pyecharts官网查看文档,里面有详细的参数说明和示例代码
from pyecharts import options as opts
#图方便就直接调包了
#from pyecharts.options import TitleOpts,也可单独导入
line.set_global_opts(
    #标题名字,位置,位置参数是百分比,也可以是像素值,如pos_left='100px'
    title_opts=opts.TitleOpts(title="一周收入",pos_left='center',pos_bottom='1%'),
    #图例,只弄了是否显示的参数,其它的把鼠标放方法上看吧
    legend_opts=opts.LegendOpts(is_show=True),
    #工具箱,打开的html右上角那些东西就是
    toolbox_opts=opts.ToolboxOpts(is_show=True),
    #视觉映射,左下角颜色条,在网页里鼠标移到数据上时会跟着变化
    visualmap_opts=opts.VisualMapOpts(is_show=True),
    #提示框,鼠标移到数据上时会显示数据值
    tooltip_opts=opts.TooltipOpts(is_show=True)
)
# 生成图表
line.render()#里面直接传字符串参数可以做为文件名字,为空默认为render.html
#找到生成的html文件,在浏览器中打开即可看到图表