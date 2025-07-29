provinces_set=set()
while True:
    try:
        raw_input=input()
        provinces_set.add(raw_input)
    except EOFError:
        break
print(f"来自于{len(provinces_set)-1}个省份。")