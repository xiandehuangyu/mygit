# Vim学习笔记
顺便练一下markdown的语法 
## 基本操作
### NORMAL模式
hjkl:上下左右
gg:移动到第一行开头
G:移动到最后一行开头
ctrl+u:向上翻半屏
ctrl+d:向下翻半屏
ctrl+f:向下翻一屏
ctrl+b:向上翻一屏
<lines>gg:移动到第<lines>行开头
<lines>G:移动到第<lines>行开头
zz/zt/zb:将光标行移动到屏幕中间/顶部/底部

### 进入INSERT模式
i:在光标前插入
I:在行首插入
a:在光标后插入
A:在行尾插入
o:在当前行下方新开一行插入
O:在当前行上方新开一行插入
s:删除光标所在字符并进入INSERT模式
S:删除当前行并进入INSERT模式

### 进入COMMAND模式
:w :保存文件
:q :退出当前文件
:wq :保存并退出当前文件
:q! :强制退出当前文件
:h{command} :查看{command}的帮助文档
<esc>:退出当前模式

### 进入VISUAL模式
v:进入VISUAL模式，可视化选择
x:剪切选中的内容
y:复制选中的内容
p:粘贴选中的内容

## 移动进阶
### 按单词移动
w:代表“word”的意思，移动到下一个单词开头
e:代表“end”的意思，移动到下一个单词结尾
b:代表“back”的意思，移动到上一个单词开头
ge:e的反向版本，移动到上一个单词结尾
web的大写版本对应的单词是连续非空字符
如:
Vim is an open-source screen-based editor.
### 基于搜索的移动
#### 行内搜索
f{char}/t{char}:移动到下一个{char}出现的处/前面
F{char}/T{char}:移动到上一个{char}出现的处/后面
; :重复上一次f/t/F/T命令
, :反向重复上一次f/t/F/T命令
#### 文件内搜索
/{pattern}:向下搜索{pattern}出现的处
?{pattern}:向上搜索{pattern}出现的处
* :等价于/{pattern} pattern是当前光标下的单词
# :等价于?{pattern}  
n :重复上一次/命令   
N :反向重复上一次/命令
### 基于标记的移动
m{mark} :标记当前位置为{mark}
'{mark} :移动到{mark}标记的位置
`{mark} :移动到上一次跳转的位置
内置的标记有:
`` :上次跳转的位置
`. :上次修改的位置
`^ :上次插入的位置
### 其它实用的跳转
^/$:移动到行首/行尾
%:匹配括号/引号/标签的位置
## 编辑进阶
### {operator}{motion} :一次编辑动作
c :代表"change",修改,删除内容并进入INSERT模式
d :代表"delete",删除内容
y :代表"yank",复制内容到系统剪切板
v :代表"visual",选中文本并进入VISUAL模式
. :重复上一次命令
u :代表"undo",撤销上一次修改
一般连按2次是作用在一行
操作+移动 可以各种组合
如: dgg :删除到第一行
ye :复制到单词结尾
d$ :删除到行尾
dt; :删除到下一个分号
y% :复制括号内的内容
### {count}{action} :重复动作count次
4j :向下移动4行
3de :删除3个单词
4p :粘贴4次
:set relativenumber :显示相对行号(可以更好的确定范围)
:set relativenumber! :取消显示相对行号
## 文本操作技巧
格式: i/a + 对象
常见对象
w/W,s,p: 单词/句子/段落
(/),[/],{/},</>
[count]{operator}{textobjects}
diw:删除当前单词
ci():修改括号内的内容
yi{}:复制括号内的内容
## 操作符与命令补充
gu/gU/g~:小写/大写/变换大小写
J:合并行
ctrl+a/ctrl+x:增加/减少数字
g ctrl+a:创建递增序列
</>:控制缩进(一般连按两次控制一行缩进)
练习的话先在v模式看下范围再用命令操作,熟练后直接操作即可
## 寄存器与宏
寄存器:用于存放内容,可理解为剪切板
一个字符对应一个寄存器,a-z,0-9,默认有"无名寄存器"
特别的寄存器:
" :默认寄存器
% :当前文件名
. :上次插入的内容
: :上次执行的命令
:reg{register} :查看对应寄存器内容
在操作前加上"{register}可指定本次操作所用的寄存器
常见用途:将想要持久保存的文本放到特定寄存器,随时进行粘贴,避免被覆盖
"ayy :复制当前行到寄存器a
"bdiw :剪切当前单词到寄存器b,删除当前单词
"cp :将寄存器c的内容粘贴出来
寄存器字面大写表示添加,而非覆盖
宏:录制一系列操作,并运行重放操作
q{register} :开始录制操作,存在寄存器中,按q结束
@{register} :重放寄存器register中的操作
@@ :重放上一次重放的操作
如:每行添加注释? qa$i//<ese><esc>q 宏a
## 命令模式
:[range]{excommand}[args]
range:适用范围,默认当前行
excommand:执行命令,如:w,q,dd,y,m,等
args:命令参数,可选
:[range] delete [x] :删除range中的行(到寄存器x),delete可简写为d
:[range] yank [x] :复制range中的内容到寄存器x,yank可简写为y
:[range] print [x] :打印range中的内容打印出来,print可简写为p
range由一个或两个{address}组成,即{address}或{address},{address}
{address}可以是:
{lineno} :行号,如3表示第3行,0表示第一行上面的虚拟行
$ :最后一行
. :当前行
% :当前文件所有行
/{pattern}/ :下个pattern所在行
address可以做加减法,.+3表示当前行往下3行,$-3表示倒数第4行
1,3 delete :删除第1到第3行
.,.+4 yank :复制当前行到当前行往下4行(共5行)的内容
$-3,$:打印最后4行的内容
:[range] copy {address} :复制range中的内容到address后面
:[range] move {address} :移动range中的内容到address后面
:[address] put {x} :把寄存器x的内容粘贴到address后面
## 批量操作
:[range] normal {command} :对range中的每一行执行normal模式下的命令command
:% I# :在每行行首插入#和一个空格
可以先对一行进行I# 操作,再对所有行进行:% .操作
多操作用宏也行:[range] normal @{register}
:[range] global/{pattern}/[cmd]
对range中包含pattern的行执行command模式下ex命令,global可简写为g
normal也是ex命令
:[range] global/{pattern}/normal {commands}
对range中包含pattern的行执行normal模式下的命令commands
:% global/TODO/delete :删除所有包含TODO的行
替换命令
:[range] s/{pattern}/{string}/[flags]
将range中包含pattern的行中的pattern替换为string,flags可选
flags:
g :全局替换
c :确认替换,需要按两次确认
i :忽略大小写
n :计数而不是替换
:% s/Vim//gn :统计Vim出现的次数,加了n不执行替换,故不用管替换为什么