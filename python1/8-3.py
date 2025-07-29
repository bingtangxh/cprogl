def f(i):
    sum=float(0.0)
    for i1 in range(i+1):
        sum+=float(i1)/float(i1+1)
    return sum

v = int(input())
print("%.4f" % f(v))
