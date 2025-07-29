a=dict(eval(input()))
b=dict(eval(input()))
for i in b.keys():
    a[i]=a.get(i,0)+b[i]
l=list(a.items())
l.sort(key=lambda x : ord(x[0]) if type(x[0])==str else x[0])
result=str(dict(l)).replace(' ','').replace('\'','\"')
print(result)