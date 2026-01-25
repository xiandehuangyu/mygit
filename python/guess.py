import random
guessnumber = random.randint(1,100)
print("在1到100之间，我选了一个数字，你猜是多少？")
guesstimes = 0
while 1:
    guess = int(input())
    guesstimes += 1
    if guess == guessnumber:
        print("恭喜你，猜对了！")
        print("你总共猜了", guesstimes, "次。")
        break
    elif guess < guessnumber:
        print("太小了，请再试一次。")
    else:
        print("太大了，请再试一次。")