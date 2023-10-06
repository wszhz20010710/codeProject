class Deque(object):
    '''用list类型来实现双端队列,因为队列是双端的,规定头尾和列表相同'''
    def __init__(self):
        '''初始化list的空对象'''
        self._list = []
    
    def add_front(self,item):
        '''向队头添加一个item元素'''
        self._list.insert(0,item)
        
    def add_rear(self,item):
        '''向队尾添加一个item元素'''
        self._list.append(item)
       
    def remove_front(self):
        '''从队头删除一个元素'''
        return self._list.pop(0)
    
    def remove_rear(self):
        '''从队尾删除一个元素'''
        return self._list.pop()
    
    def is_empty(self):
        '''判断是否为空'''
        return self._list == []
    
    def size(self):
        '''求队列大小'''
        return len(self._list)

if __name__ == "__main__":
    deque = Deque()
    deque.add_front(1)
    deque.add_front(2)
    deque.add_rear(3)
    deque.add_rear(4)
    deque.travel()
    print(deque.remove_front())
    print(deque.remove_front())
    print(deque.remove_rear())
    print(deque.remove_rear())
      
    
            