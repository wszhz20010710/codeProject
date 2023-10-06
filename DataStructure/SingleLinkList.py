class SingleLinkNode(object):
    #初始化单向链表的结点
    def __init__(self,elem):
        self.elem = elem    #初始化数据
        self.next = None    #初始化链接为空
        
class SingleLinkList(object):
    #单链表需要给出头结点属性
    def __init__(self,node=None):
        self._head = node
        
    def is_empty(self):#链表是否为空
        return self._head is None
    
    def length(self):#链表长度，只需要返回结点数目
        #current为游标，用来移动遍历结点
        current = self._head
        #count用来记录结点数量
        count = 0
        while current != None:
            count += 1
            current = current.next
        return count
    
    def travel(self):#遍历整个链表
        current = self._head
        while current != None:
            print(current.elem,end=" ")#打印游标指到的每个元素
            current = current.next
        print("")
           
    def add(self,item):#链表头部添加元素
        node = SingleLinkNode(item)
        node.next = self._head
        self._head = node
        
    
    def append(self,item):# 链表尾部添加元素
        node = SingleLinkNode(item)
        #列表为空时需要单独考虑
        if self.is_empty():
            self._head = node
        else:
            current = self._head
            while current.next != None:
                current = current.next
            current.next = node
        
    def insert(self,pos,item):# 指定位置添加元素
        node = SingleLinkNode(item)
        if pos <= 0:
            self.add(item)
        elif  pos > (self.length()-1):
            self.append(item)
        else:
            cur = self._head
            count = 0
            while count != (pos-1):
                cur = cur.next
                count += 1
            #退出循环时，cur指向pos的前一个元素
            node.next = cur.next
            cur.next = node
            
    def remove(self,item):# 删除节点
        cur = self._head
        pre = None
        while cur.next != None:
            if cur.elem == item:
                #先要判断是否是头节点
                #头节点
                if cur == self._head:
                    self._head = cur.next
                else:
                    pre.next = cur.next
                break
                #此时删除搜索到的第一个元素，若想删除所有item
                #则将break改为cur = cur.next
            else:
                pre = cur
                cur = cur.next

        
        
        
    def search(self,item): # 查找节点是否存在，存在返回真否则为假
        current = self._head
        while current != None:
            if current.elem == item:
                return True
            else:
                current = current.next
        return False
            

if __name__ == "__main__":
    li = SingleLinkList()
    print(li.is_empty())
    print(li.length())
    li.append(2)
    li.append(0)
    li.append(2)
    li.append(3)
    li.add(2023)
 
    li.insert(-1,3.14)
    li.insert(100,666)
    li.insert(2,888)
    li.travel()
    li.remove(2)
    li.travel()
    print(li.is_empty())
    
    