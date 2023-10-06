def ShellSort(a_list):  
    '''对一个列表进行希尔排序'''
    n = len(a_list) 
    gap = n // 2
    while gap > 0:
        for i in range(gap,n):
            for j in range(i,0,-1):
                if a_list[j] < a_list[j-gap]:
                    a_list[j],a_list[j-gap] = a_list[j-gap],a_list[j]
        gap = gap // 2
        
if __name__ == "__main__":
    li = [54,26,93,17,77,31,44,55,20]
    ShellSort(li)
    print(li)