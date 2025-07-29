raw_str=input()
fourth={}
for third in raw_str:
    if third in fourth:
        fourth[third]+=1
    else:
        fourth[third]=1

sorted_list = sorted(fourth.items(), key=lambda x: x[1], reverse = True)
print(sorted_list[0][0],sorted_list[0][1],sep=',')