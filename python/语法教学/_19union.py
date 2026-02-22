#Union联合类型,表示一个变量可以是多种类型中的一种,用法:Union[类型1, 类型2,...],需要导入typing模块
#好像该放在类型注释后面,不过都属于挺后面的,类型注释也就在texing最后提了下,放这里应该影响不大
from typing import Union
mylist : list[Union[int, str]] = [1, 'hello', 2, 'world']
mydict : dict[str, Union[int, str]] = {'name': '张三', 'age': 25, 'city': 'Beijing'}
def func(a: Union[int, str]) -> Union[int, str]:
    return str(a) + '1'
print(func(1)) # 11
print(func('hello')) # hello1