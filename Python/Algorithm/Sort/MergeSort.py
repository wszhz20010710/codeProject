def MergeSort(a_list):
    '''对一个列表进行归并排序'''
    #拆分到列表长度为1停止
    if len(a_list) <= 1:
        return a_list
    #二分分解
    mid = len(a_list) // 2
    #分成a_list[:mid],a_list[mid:]
    #left和right代表归并排序后的有序序列
    left_li = MergeSort(a_list[:mid])
    right_li = MergeSort(a_list[mid:])
    #对left和right两个有序序列进行合并
    left_pointer,right_pointer = 0,0
    result = []
    while left_pointer < len(left_li) and right_pointer < len(right_li): 
        if left_li[left_pointer] < right_li[right_pointer]:
            result.append(left_li[left_pointer])
            left_pointer += 1
        else:
            result.append(right_li[right_pointer])
            right_pointer += 1
    #添加剩余元素
    result += left_li[left_pointer:]
    result += right_li[right_pointer:]
    return result
         
if __name__ == "__main__":
    li = [54,26,93,17,77,31,44,55,20]
    sorted_li = MergeSort(li)
    print(li)
    print(sorted_li)
    #merge_sort [54,26,93,17,77,31,44,55,20]
    #left_li = merge_sort[54,26,93,17]  
        #left_li = merge_sort[54,26]        
             #left_li = merge_sort[54]
                #left_li = [54]   right_li = merge_sort[26] 
                #left_li = [54]   right_li = [26]
                #result = [54,26] 
    #right_li同理
#每次返回的result如下              
# [26, 54]
# [17, 93]
# [17, 26, 54, 93]
# [31, 77]
# [20, 55]
# [20, 44, 55]
# [20, 31, 44, 55, 77]
# [17, 20, 26, 31, 44, 54, 55, 77, 93]         