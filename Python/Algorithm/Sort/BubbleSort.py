def BubbleSort(a_list):
    '''对一个列表进行冒泡排序'''
    l = len(a_list)
    if l == 0:
        return ValueError
    for j in range(l-1,0,-1):
        #j表示每次遍历需要比较的次数，由n-1降到1
        for i in range(j):
            count = 0
            if a_list[i] > a_list[i+1]:
                a_list[i],a_list[i+1] = a_list[i+1],a_list[i]
                count += 1
        #最优情况，遍历一次发现没有可交换的元素
        if count == 0:
            return

if __name__ == "__main__":
    li = [54,26,93,17,77,31,44,55,20]
    BubbleSort(li)
    print(li)