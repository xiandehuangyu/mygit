from pyecharts.charts import Map
from pyecharts.options import VisualMapOpts
# 构建对象
map = Map()
# 准备数据
data = [("北京市", 100), ("上海市", 200), ("广东省", 300), ("重庆市", 400)]
# 添加数据
map.add("商户数量", data, "china")# c必须小写,其它地图的话,个人发现就是用中文名,如,美国,北京
# 设置全局配置
map.set_global_opts(
    visualmap_opts=VisualMapOpts(
        is_show=True,
        is_piecewise=True,#手动控制范围
        pieces=[
            {"min": 100, "max": 250, "label": "100-250", "color": "#006edd"},
            {"min": 250, "max": 400, "label": "250-400", "color": "#ffde33"},
            #范围设置,label设置显示的标签,color设置颜色
    ])
)
# 绘图
map.render()