#数学建模常用三大库：numpy、pandas、matplotlib
#分别负责数值计算、表格处理、可视化
#都只讲下用得到的，要完整学习建议看手册
#numpy:https://www.numpy.org.cn/reference/
import numpy as np
#numpy核心是ndarray(N维数组),它是一个同类型元素的多维容器
#创建数组
#1.创建
a = np.array([1,2,3,4,5])
print(a)
print(type(a)) #numpy.ndarray
b = np.array([[1,2,3],[4,5,6],[7,8,9],[10,11,12]])
print("数组形状:",b.shape)#指4行3列,这里shape是内部属性，不是函数，所以shape后面没有括号
#2.索引操作
#和list一样
print(b[0:2])
print(b[1][2])
print(b[1,2])#这里的索引是行列的，所以是b[行,列],这个是特有的
#3.运算
print(np.array([1,2,3]) + np.array([4,5,6]))#对应位置进行运算
print(np.array([1,2,3]) * np.array([4,5,6]))
#4.改变形状
#真正的改变的话要重新赋值
b.reshape(2,6)#这里是内部方法，有括号要传参数，注意要保证元素个数匹配
#传入参数是-1的话就直接变成一维数组
print(b)#可以发现b没有变
#如果操作刚好是转置的话，可以用.transpose()方法或者直接.T属性
print(b.transpose())
#5.进阶
arr1=np.array([1,2,3])
arr2=np.array([4,5,6])
print(np.dot(arr1,arr2))#点乘
print(b.mean())#求均值 #写成np.mean(b)也行，一个是调用方法，一个是调用函数
print(b.std())#求标准差
print(b.sum())#求和 还有.max() .min()
c=np.array([[4,1,2],[9,99,7],[8,5,3]])
print(np.sort(c))#sort的话只能直接用numpy里的函数，排序的话只排每行，不排列
print(c>5)#会输出逻辑矩阵，用于数据筛选
print(c[(c>5) & (c<10)])#筛选出大于5且小于10的元素
#与python的逻辑运算相同，但不能用and或or，只能用&或|
#6.保存和读取
"""
np.save('my_array',b)#保存为'my_array.npy'文件
c=np.load('my_array.npy')#读取文件
"""



#上面是简略的，下面补充和进阶
#1.特殊数组
zeros_mat = np.zeros((3, 3))  # 3x3全0矩阵（初始化空矩阵）
ones_mat = np.ones((2, 4))    # 2x4全1矩阵
eye_mat = np.eye(4)           # 4阶单位矩阵（线性代数常用）
rand_mat = np.random.rand(2, 3)  # 2x3随机矩阵（元素0-1均匀分布）
randn_mat = np.random.randn(2, 3) # 2x3随机矩阵（正态分布）
arange_arr = np.arange(0, 10, 2)  # 等差数列：0,2,4,6,8（起始，终止，步长）
linspace_arr = np.linspace(0, 1, 5)  # 0到1均分5个点：[0,0.25,0.5,0.75,1]
print(zeros_mat.ndim)#维度
print(zeros_mat.size)#元素个数
print(zeros_mat.dtype)#数据类型
#2.索引，根据特有的操作衍生的操作
mat=np.array([[1,2,3],[4,5,6],[7,8,9]])
print(mat[:, 1])      # 取所有行的第2列 → [2,5,8]（一维数组）
print(mat[2, :])      # 取第3行的所有列 → [7,8,9]
#3.运算,直接找ai汇总了一下
"""
a = np.array([1, 2, 3])
b = np.array([4, 5, 6])
mat1 = np.array([[1,2],[3,4]])
mat2 = np.array([[5,6],[7,8]])

# 1. 基础算术运算（元素级）
print(a + b)  # [5,7,9]（对应元素相加）
print(a * b)  # [4,10,18]（对应元素相乘，不是矩阵乘法！）
print(mat1 - mat2)  # [[-4,-4],[-4,-4]]
print(mat1 / 2)     # [[0.5,1],[1.5,2]]
print(a ** 2)       # [1,4,9]（元素平方）

# 2. 矩阵运算
# 矩阵乘法：@ 或 np.dot()
mat_mul = mat1 @ mat2  # 等价于 np.dot(mat1, mat2)
print(mat_mul)  # [[1*5+2*7, 1*6+2*8], [3*5+4*7, 3*6+4*8]] → [[19,22],[43,50]]
# 矩阵转置
print(mat1.T)  # [[1,3],[2,4]]
# 矩阵求逆（需是方阵且可逆）
inv_mat = np.linalg.inv(mat1)
print(inv_mat)  # [[-2. , 1. ], [1.5, -0.5]]
# 行列式计算
det = np.linalg.det(mat1)
print(det)  # 输出 -2.0
# 求解线性方程组 Ax = b
A = np.array([[1,2],[3,4]])
b = np.array([5,11])
x = np.linalg.solve(A, b)
print(x)  # 输出 [1. 2.](x=1, y=2)

# 3. 统计运算
mat = np.array([[1,2,3],[4,5,6],[7,8,9]])
print(np.sum(mat))          # 所有元素和 → 45
print(np.sum(mat, axis=0))  # 按列求和 → [12,15,18]
print(np.sum(mat, axis=1))  # 按行求和 → [6,15,24]
print(np.mean(mat))         # 平均值 → 5.0
print(np.max(mat))          # 最大值 → 9
print(np.min(mat, axis=1))  # 按行求最小值 → [1,4,7]
print(np.argmax(mat))       # 最大值的索引（展平后）→ 8
print(np.cumsum(mat))       # 累计和 → [1,3,6,10,15,21,28,36,45]
"""
#4.改变形状
#变为一维数组
mat = np.array([[1,2],[3,4],[5,6]])
print(mat.flatten())  # [1 2 3 4 5 6]
print(mat.ravel())   # 同上
#合并数组
a = np.array([[1,2],[3,4]])
b = np.array([[5,6],[7,8]])
# 按行合并（垂直拼接）：行数增加
v_stack = np.vstack((a, b))  # [[1,2],[3,4],[5,6],[7,8]]
# 按列合并（水平拼接）：列数增加
h_stack = np.hstack((a, b))  # [[1,2,5,6],[3,4,7,8]]
#拆分数组
split_mat = np.split(v_stack, 2)  #按行拆分为对应个数个子数组
print(split_mat[0])  # [[1,2],[3,4]]
print(split_mat[1])  # [[5,6],[7,8]]
#5.广播机制
#维度不同时自动扩展维度匹配
mat = np.array([[1,2],[3,4],[5,6]])
scalar = 2
vec = np.array([10, 20])
# 标量与矩阵运算(广播到所有元素)
print(mat * scalar)  # [[2,4],[6,8],[10,12]]
# 向量与矩阵运算(vec 广播到每一行)
print(mat + vec)     # [[11,22],[13,24],[15,26]]
#6.随机数(用内置的方便些，random包的函数也有)
"""
# 1. 设置随机种子
np.random.seed(42)  # 固定种子后，每次运行生成的随机数都一样

# 2. 生成各类分布的随机数（建模模拟常用）
uniform_rand = np.random.uniform(1, 10, size=(2,3))  # 1-10均匀分布,2行3列
normal_rand = np.random.normal(0, 1, size=5)         # 正态分布均值0,(标准差1),5个值
poisson_rand = np.random.poisson(lam=5, size=10)     # 泊松分布(λ=5),10个值
integers_rand = np.random.randint(0, 100, size=(3,3)) # 0-99整数,3行3列

# 3. 随机抽样与洗牌（建模中数据划分/打乱常用）
arr = np.arange(10)
np.random.shuffle(arr)  # 原地打乱数组 → 比如 [8 1 5 0 7 2 9 4 3 6]
sample = np.random.choice(arr, size=3, replace=False) # 无放回抽样3个 → 比如 [8 5 7]
weighted_sample = np.random.choice([1,2,3], size=5, p=[0.2,0.5,0.3]) # 按权重抽样
"""
#7.缺失和异常值处理
"""
# 1. 创建含缺失值的数组(np.nan 仅支持浮点型)
data = np.array([[1, 2, np.nan], [4, np.nan, 6], [7, 8, 9]], dtype=np.float64)

# 2. 检测缺失值
print("缺失值位置(True表示缺失):\n", np.isnan(data))
print("每列缺失值个数：", np.sum(np.isnan(data), axis=0))  # [0 1 1]

# 3. 处理缺失值（建模中常用填充/删除）
# 方式1:用均值填充缺失值
mean_vals = np.nanmean(data, axis=0)  # 计算每列非缺失值的均值
data[np.isnan(data)] = np.take(mean_vals, np.where(np.isnan(data))[1])
print("填充缺失值后：\n", data)

# 方式2:删除含缺失值的行(需转为二维数组操作)
data_raw = np.array([[1, np.nan], [3,4], [5,6]])
clean_data = data_raw[~np.isnan(data_raw).any(axis=1)]  # 保留无缺失值的行
print("删除缺失值行后：\n", clean_data)  # [[3 4], [5 6]]

# 4. 异常值处理(比如3σ原则)
arr = np.random.normal(10, 2, size=100)  # 生成均值10,标准差2的数组
mean = np.mean(arr)
std = np.std(arr)
# 筛选出3σ内的正常值
normal_arr = arr[(arr > mean-3*std) & (arr < mean+3*std)]
print("异常值过滤前数量：", len(arr))
print("异常值过滤后数量：", len(normal_arr))
"""
#8.线代扩展操作(我看不懂)
"""
# 1. 特征值与特征向量（PCA、特征分析常用）
mat = np.array([[1,2],[3,4]])
eigenvalues, eigenvectors = np.linalg.eig(mat)
print("特征值：", eigenvalues)       # 输出 [-0.37228132  5.37228132]
print("特征向量矩阵：\n", eigenvectors)  # 每列是对应特征值的特征向量

# 2. 奇异值分解（SVD，数据降维、矩阵近似常用）
mat = np.array([[1,2,3],[4,5,6],[7,8,9]])
U, S, VT = np.linalg.svd(mat)
print("左奇异矩阵U：\n", U)
print("奇异值S：", S)               # [16.84810335 1.06836951 0.        ]
print("右奇异矩阵VT：\n", VT)

# 3. 范数计算（距离、误差分析常用）
vec = np.array([3,4])
mat = np.array([[1,2],[3,4]])
print("向量L2范数（欧氏距离）：", np.linalg.norm(vec))  # 5.0
print("向量L1范数（曼哈顿距离）：", np.linalg.norm(vec, ord=1))  # 7.0
print("矩阵Frobenius范数：", np.linalg.norm(mat, ord='fro'))  # 5.477...

# 4. 矩阵求伪逆（非方阵/奇异矩阵求解常用）
singular_mat = np.array([[1,2],[2,4]])  # 奇异矩阵（行列式为0）
pinv_mat = np.linalg.pinv(singular_mat)
print("矩阵伪逆：\n", pinv_mat)
"""
#9.数组高阶操作
'''
# 1. 通用函数（ufunc）：向量化的数学函数（比Python原生函数快）
arr = np.array([0, np.pi/2, np.pi])
print(np.sin(arr))  # [0. 1. 0.]（正弦）
print(np.exp(arr))  # 指数运算
print(np.log(arr+1))# 对数运算（+1避免log(0)）

# 2. 自定义向量化函数（将普通函数转为向量化）
def my_func(x):
    """自定义函数：x>0返回x²，否则返回x"""
    if x > 0:
        return x**2
    else:
        return x

# 转为向量化函数，可直接作用于数组
vec_func = np.vectorize(my_func)
arr = np.array([-2, -1, 0, 1, 2])
print(vec_func(arr))  # [-2 -1  0  1  4]

# 3. 广播的进阶应用（多维数组匹配）
# 例：计算每个样本到中心点的欧氏距离
samples = np.random.rand(5, 3)  # 5个样本，3个特征
center = np.mean(samples, axis=0)  # 中心点（3个特征的均值）
# 广播计算每个样本与中心点的差值
diff = samples - center
# 计算距离（向量化，无需循环）
distances = np.sqrt(np.sum(diff**2, axis=1))
print("各样本到中心点的距离：", distances)
'''