def SelectSort(a_list):
    '''对一个列表进行选择排序'''
    l = len(a_list)
    for i in range(l-1):
        min_index = i
        for j in range(i+1,l):
            if a_list[j] < a_list[min_index]:
                min_index = j
        if min_index != i:
            a_list[i],a_list[min_index] = a_list[min_index],a_list[i]

if __name__ == "__main__":
    li = [54,26,93,17,77,31,44,55,20]
    SelectSort(li)
    print(li)