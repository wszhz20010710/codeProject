def BinSearch0(arr,target):
    """非递归实现二分法搜索有序数组arr中的target"""
    left = 0
    right = len(arr) - 1
    
    while left <= right:
        mid = (left + right) // 2
        
        if arr[mid] == target:
            return mid
        elif arr[mid] > target:
            #说明目标在左半部分
            right = mid - 1 
        else:
            #说明目标在右半部分
            left = mid + 1
    return -1

def BinSearch1(arr,target,left,right):
    """递归实现二分法搜索有序数组arr中的target"""
    if left <= right:
        mid = (left + right) // 2
        
        if arr[mid] == target:
            return mid
        elif arr[mid] > target:
            return BinSearch1(arr,target,left,mid-1)
        else:
            return BinSearch1(arr,target,mid+1,right)
    return -1
        
if __name__ == "__main__":
    arr = [1,2,3,4,5,6,7,8]
    target = 3
    index0 = BinSearch0(arr,target)
    index1 = BinSearch1(arr,target,0,len(arr)-1)
    print("目标元素%d在数组中的索引为%d"%(target,index0))    
    print("目标元素%d在数组中的索引为%d"%(target,index1))        