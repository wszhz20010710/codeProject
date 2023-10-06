def QuickSort(a_list,start,end):
    '''对一个列表进行快速排序'''
    if start >= end:
        return
    mid_value = a_list[start]
    low = start
    high = end
    while low < high:
        #high左移
        while low < high and a_list[high] >= mid_value:
            high -= 1
        a_list[low] = a_list[high]
        #low右移
        while low < high and a_list[low] < mid_value:
            low += 1
        a_list[high] = a_list[low]
    #退出循环时，low=high
    a_list[low] = mid_value
    #利用递归
    QuickSort(a_list,start,low-1)
    QuickSort(a_list,low+1,end)

#简化版本
def quicksort(arr):
    if len(arr) <= 1:
        return arr
    else:
        pivot = arr[0] #设定第一个元素为基准元素
        left = [x for x in arr[1:] if x < pivot]
        right = [x for x in arr[1:] if x >= pivot]
        return quicksort(left) + [pivot] + quicksort(right)
       
if __name__ == "__main__":
    li = [54,26,93,17,77,31,44,55,20]
    QuickSort(li,0,len(li)-1)
    print(li)
    