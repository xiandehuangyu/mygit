#json相当于一种中转数据格式,便于在不同语言之间传递数据.
#python转json:将python数据类型转换为json字符串
#json转python:将json字符串转换为python数据类型
"""
JSON类型	    Python类型	              备注
对象{...}	      dict字典         JSON的键必须是字符串
数组[...]	      list列表       
字符串str	      str字符串         JSON字符串必须用双引号
数字int/float	int/float数字       JSON无复数、长整型
true/false	     True/False	          注意大小写差异
null	          None	          Python用 None 表示空值
"""
import json
#python数据类型(列表,列表每个元素为字典,字典)转换为json字符串
#我学到这里有点懵,因为上面这些是对应的,说明可以互相转,但又说只转列表和字典
#然后又试了下转数字和字符串,是可以的,后面就查了下解释,如下,解释之后是真正的演示使用
#单独装其它数据时,没有什么意义,因为装键值对时才知道传的是什么,而传单独数据时
#也能通过加键值对来说明
"""
你要给朋友寄 “传智播客的股票信息”，信息包括：公司名（字符串）、股价（数字）、是否上市（布尔值）。
情况 1:用 “分格收纳盒（字典）” 装（正确做法）
你把这些零散的小零件（公司名、股价）放进带标签的分格盒（字典）里：
分格盒标签（键）：“公司名”“股价”“是否上市”；
每个格子里的东西(值):“传智播客”、19.99、true。
然后把这个分格盒放进 JSON 快递箱 —— 对方收到后，一看标签就知道每个格子里是什么，清清楚楚。
# 分格盒（字典）装小零件
data = {"公司名": "传智播客", "股价": 19.99, "是否上市": True}
# 放进 JSON 快递箱（序列化）
json_str = json.dumps(data)
情况 2:用 “长条收纳盒（列表）” 装（也正确）
如果要寄多组股票信息，就用长条收纳盒（列表），里面再放多个分格盒：
# 长条盒(列表)里装2个分格盒(字典)
data = [
    {"公司名": "传智播客", "股价": 19.99},
    {"公司名": "腾讯", "股价": 300}
]
json_str = json.dumps(data)
情况 3:直接装单个小零件(没人这么干)
你如果只往快递箱里塞一个小零件(比如只塞数字19.99),对方收到后一脸懵:“这19.99 是啥？股价？体重？”
没有任何上下文，完全没意义。
这就是为什么没人单独序列化字符串 / 数字，必须用字典 / 列表（大盒子）给小零件 “贴标签、分好类”。
"""
_data = {
    "name": "传智播客",
    "stock_code": "003032",
    "price": 19.99,
    "is_listed": True,
    "growth_days": 7,
    "null_value": None,
    "tags": ["教育", "科技"]
}
#通过json.dumps(data)方法将python数据类型转换为json字符串
json_data = json.dumps(_data)
#多传入一个参数可显示中文,下面的意思是不将中文转ascii码,即直接输出
#为true时,中文会被转为unicode编码
#json_data = json.dumps(_data,ensure_ascii=False)
print(json_data)
print(type(json_data))
#通过json.loads(data)方法将json字符串转换为python数据类型
python_data=json.loads(json_data)
print(python_data)
print(type(python_data))
