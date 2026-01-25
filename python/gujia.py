name = "传智播客"
stock_code = """003032"""
stock_price = 19.99
growth = 1.2
growth_days = 7
print(f"公司:{name},股票代码:{stock_code},当前股价:{stock_price}")
print("每日增长系数是:%f，经过%d天的增长后，股价达到了:%.2f"% ( growth,growth_days , growth ** growth_days * stock_price ) )
