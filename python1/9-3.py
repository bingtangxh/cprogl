x=int(input())
sum=0
for i in range (x):
    for i1 in range (i+1):
        sum+=(i1+1)
# print(f"sum={sum}")
print("sum=%d,%d"%(sum,sum+1))