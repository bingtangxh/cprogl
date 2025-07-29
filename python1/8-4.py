def caculate(*t):
    product=1
    for multiplier in t:
        product*=multiplier
    return product

s = input().split()            #接受输入字符串并按空格分拆，存入列表，列表成员为字符串类型
t = [float(x) for x in s]    #使用列表推导将列表s中的成员全部转换成浮点数，存入另一个列表t
print("%.4f" % caculate(*t))

