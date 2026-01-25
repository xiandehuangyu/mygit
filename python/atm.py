cunkuanq = 10000
def cunkuan():
    global cunkuanq
    amount = int(input("请输入存款金额："))
    cunkuanq += amount
    print(f"存款成功！当前余额为：{cunkuanq}元")
    input()
    caidan()
def qukuan():
    global cunkuanq
    amount = int(input("请输入取款金额："))
    if amount > cunkuanq:
        print("余额不足，取款失败！")
    else:
        cunkuanq -= amount
        print(f"取款成功！当前余额为：{cunkuanq}元")
    input()
    caidan()

def chaxun():
    global cunkuanq
    print(f"当前余额为：{cunkuanq}元")
    input()
    caidan()

def caidan():
    print("欢迎使用ATM机")
    while True:
        print("请选择服务：")
        print("1. 取款")
        print("2. 存款")
        print("3. 查询余额")
        print("4. 退出")
        choice = input("请输入您的选择：")
        if choice == '1':
            qukuan()
        elif choice == '2':
            cunkuan()
        elif choice == '3':
            chaxun()
        elif choice == '4':
            print("感谢使用ATM机，再见！")
            break
        else:
            print("无效选择，请重新输入。")
caidan()