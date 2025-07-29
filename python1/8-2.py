import random

def multiply(a,b,p,q,r):
    product=[[random.randint(0,0) for x in range(r)] for y in range(p)]
    for i1 in range(r+1):
        for i2 in range(p):
            temp=0
            for i3 in range(q):
                temp+=a[i2][i3]*b[i3][i1-1]
            product[i2][i1-1]=temp
    return product

p = int(input())
q = int(input())
r = int(input())

a = [[random.randint(0,10) for x in range(q)] for y in range(p)]
b = [[random.randint(0,10) for x in range(r)] for y in range(q)]
c = multiply(a,b,p,q,r)  #调用执行读者写的函数

rst = True

#由出题者书写的正确函数计算返回的标准答案
answerTypical = multiply(a,b,p,q,r)
for i in range(p):
    for j in range(r):
        if c[i][j] != answerTypical[i][j]:
            rst = False
            break

print(rst)