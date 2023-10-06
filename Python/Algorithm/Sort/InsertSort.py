def InsertSort(a_list):
    '''对一个列表进行插入排序'''
    n = len(a_list) 
    #无序序列
    for i in range(1,n):
        #有序序列
        for j in range(i,0,-1):
            if a_list[j] < a_list[j-1]:
                a_list[j],a_list[j-1] = a_list[j-1],a_list[j]
                
if __name__ == "__main__":
    li = [54,26,93,17,77,31,44,55,20]
    InsertSort(li)
    print(li)