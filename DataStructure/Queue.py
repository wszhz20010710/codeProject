class SQueue(object):
    '''队列的list列表对象实现'''
    def __init__(self):
        #初始化一个列表对象
        self._items = []
        
    def is_empty(self):
        '''判断是否为空'''
        return self._items == []
    
    def enqueue(self,item):
        '''向队列尾部添加元素item'''
        self._items.insert(0,item)
    
    def dequeue(self):
        '''从队列头部删除一个元素'''
        #空队列
        if self.is_empty():
            return
        else:
            return self._items.pop()
     
    def top(self):
        '''弹出最早入队元素不删除'''
        if self.is_empty():
            return
        else:
            return self._items[-1]
    
    def size(self):
        '''求队列大小,同length()'''
        return len(self._items)



import SingleLinkList
from SingleLinkList import SingleLinkNode
class LQueue(object):
    '''队列的单链表实现'''
    def __init__(self,node = None):
        '''初始化,调用SingleLinkNode'''
        self._head = None
    
    def is_empty(self):
        '''判断队列是否为空'''
        return self._head is None
        
    def enqueue(self,item):
        '''向队列尾部添加元素item'''
        node = SingleLinkNode(item)
        node.next = self._head
        self._head = node
        
    def dequeue(self):
        '''从队列头部删除一个元素'''
        #空队列
        if self.is_empty():
            return
        elif self.size() == 1:
            self._head = None
        else:   
            prev = None
            cur = self._head
            while cur.next != None:
                prev = cur
                cur = cur.next   
            #cur指针指向链表尾元素,prev指向倒数第二个元素
            prev.next = None
            return cur.elem
    
    def top(self):
        '''弹出最早入队元素不删除'''
        if self.is_empty():
            return 
        cur = self._head
        while cur.next != None:
            cur = cur.next   
        #cur指针指向链表尾元素
        return cur.elem
          
    def size(self):
        '''求队列大小,同length()'''
        #current为游标，用来移动遍历结点
        current = self._head
        #count用来记录结点数量
        count = 0
        while current != None:
            count += 1
            current = current.next
        return count
    
if __name__ == "__main__":
    queue0 = LQueue()
    print(queue0.is_empty())
    queue0.enqueue(1)
    queue0.enqueue(2)
    queue0.enqueue(3)
    queue0.enqueue(4)
    queue0.enqueue(5)
    #5 4 3 2 1
    print(queue0.size())
    print(queue0.top())
    queue0.dequeue()
    #5 4 3 2
    print(queue0.top())
    queue0.dequeue()
    #5 4 3
    print(queue0.top())
    queue0.dequeue()
    #5 4
    print(queue0.top())
    queue0.dequeue()
    #5
    print(queue0.top())
    queue0.dequeue()
    #None
    print(queue0.top())
    print(queue0.size())
    print(queue0.is_empty())
    print("")
    queue1 = SQueue()
    print(queue1.is_empty())
    queue1.enqueue(1)
    queue1.enqueue(2)
    queue1.enqueue(3)
    queue1.enqueue(4)
    queue1.enqueue(5)
    #5 4 3 2 1
    print(queue1.size())
    print(queue1.top())
    queue1.dequeue()
    #5 4 3 2
    print(queue1.top())
    queue1.dequeue()
    #5 4 3
    print(queue1.top())
    queue1.dequeue()
    #5 4
    print(queue1.top())
    queue1.dequeue()
    #5
    print(queue1.top())
    queue1.dequeue()
    #None
    print(queue1.top())
    print(queue1.size())
    print(queue1.is_empty())
    
      
        
        