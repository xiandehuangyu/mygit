#上面三种容器都是有序的
#索引的特殊操作切片均可使用
#语法:序列[起始下标:终止下标:步长]
#省略起始下标或终止下标时，默认从头开始或到尾结束,省略步长时默认为1
#步长可以为负数，表示逆序

#集合是无序的，不允许重复元素，但可修改
#集合字面量 {元素1, 元素2, 元素3,...}
#定义集合变量 变量名 = {元素1, 元素2, 元素3,...}
#定义空集合变量 变量名 = set() 
#变量名={}定义的是字典，不能直接用空{}定义集合
myset = {1,True,"hello",(1,2,3),4.1,2}
#集合.add(元素) 向集合中添加元素
print(myset)
myset.add(5)
print(myset)
myset.add(1)
print(myset)#打印顺序与上面给的不同,因为无序,同时可以看到1没有添加,而其本身是能修改的
#集合.remove(元素) 从集合中删除元素
myset.remove(1)
print(myset)
#集合.pop() 随机删除集合中的一个元素,并返回该元素
a=myset.pop()
print(a)
print(myset)
#集合.clear() 清空集合
myset.clear()
print(myset)
#集合.union(集合) 并集(所有元素)
myset1 = {1,2,3}
myset2 = {3,4,5}
myset3 = myset1.union(myset2)
print(myset3)
#集合.intersection(集合) 交集(前者有而后者也有的元素)
myset4 = {1,2,3}
myset5 = {2,3,4}
myset6 = myset4.intersection(myset5)
print(myset6)
#集合.difference(集合) 差集(前者有而后者没有的元素)
myset7 = {1,2,3}
myset8 = {2,3,4}
myset9 = myset7.difference(myset8)
print(myset9)
#集合.difference_update(集合) 差集更新(在前者中删除与后者相同的元素)
myset10 = {1,2,3}
myset11 = {2,3,4}
myset10.difference_update(myset11)
print(myset10)
print(myset11)
#len(集合) 集合元素个数 略
#for 变量 in 集合: 遍历集合 略(不能用while)