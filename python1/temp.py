a,b=input().split(' ')
a,b=eval(a),eval(b)
sum=sum1=0
for i in range (b):
    for i1 in range (i+1):
        sum+=a*(10**i1)
print(sum)