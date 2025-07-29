set2={6,7,8,9,10}
raw_input=input()
selection=[int(num) for num in raw_input.split(',')]
selected=set(selection)
selected_elem=[element for element in set2-selected]
selected_elem.sort(reverse=False)
result_str=' '.join(map(str,selected_elem))
print(result_str)