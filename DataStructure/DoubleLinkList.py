class DoubleLinkNode(object):
    '''初始化双向链表结点'''
    def __init__(self,item):
        self.elem = item    #结点元素为输入元素
        self.prev = None    #初始化前驱节点为None
        self.next = None    #初始化后继结点为None
        
class DoubleLinkList(object):
    '''初始化双向链表，定义其中操作函数''' 
    def __init__(self, node = None):
        self._head = node
    
    def is_empty(self):
        '''判断链表是否为空'''
        return self._head is None
    
    def length(self):
        '''求双向链表长度'''
        cur = self._head #初始化cur指针用来遍历列表
        count = 0   #初始化count用来计数
        while cur != None:
            count += 1
            cur = cur.next
        return count
    
    def travel(self):
        '''遍历整个链表'''
        cur = self._head
        while cur != None:
            print(cur.elem, end = " ")
            cur = cur.next
        print("")
    
    def add(self,item):
        '''向双向链表头部添加元素'''
        node = DoubleLinkNode(item)
        if self.is_empty():
            #如果是空表则将_head指向node
            self._head = node
        else:
            #将node的next指向_head的头结点
            node.next = self._head
            #将_head头结点指向node
            self._head = node
            #将原来头结点的prev指向node
            node.next.prev = node
            
    def append(self,item):
        '''向双向链表尾部添加元素'''
        node = DoubleLinkNode(item)
        if self.is_empty():
            #如果是空表则将_head指向node
            self._head = node
        else:
            #初始化指针cur用来指向尾部
            cur = self._head    
            while cur.next != None:
                cur = cur.next
            #将尾结点cur的next指向node
            cur.next = node
            #将node的prev指向尾结点cur
            node.prev = cur
            
    def insert(self,pos,item):
        '''向指定位置插入元素'''
        if pos <= 0:
            self.add(item)
        elif pos > (self.length()-1):
            self.append(item)
        else:
            node = DoubleLinkNode(item)
            cur = self._head
            count = 0
            while count != pos:
                count += 1
                cur = cur.next
            #退出循环时cur指向pos位置
            node.next = cur
            node.prev = cur.prev
            cur.prev.next = node
            cur.prev = node
            
    def remove(self,item):
        '''删除元素'''
        #空表情况
        if self.is_empty():
            return
        else:
            cur = self._head
            while cur != None:
                #对元素进行搜索，找到此元素
                if cur.elem == item:
                    #如果首节点即是需要删除的元素
                    if cur == self._head:
                        #将head指向第二个结点
                        self._head = cur.next
                        #判断双向链表是否只有一个结点
                        #如果不止一个结点
                        if cur.next != None:
                            cur.next.prev = None
                    else:
                        cur.prev.next = cur.next
                        #判断是否是尾结点
                        if cur.next != None:
                            cur.next.prev = cur.prev
                    break 
                    #此时删除搜索到的第一个元素，若想删除所有item
                    #则将break改为cur = cur.next
                else:
                    cur = cur.next

    def search(self,item): #
        '''查找节点是否存在，存在返回真否则为假'''
        current = self._head
        while current != None:
            if current.elem == item:
                return True
            else:
                current = current.next
        return False    
        

if __name__ == "__main__":
    ll = DoubleLinkList()
    print(ll.is_empty())
    print(ll.length())
    
    ll.append(1)
    print(ll.is_empty())
    print(ll.length())
    
    ll.append(2)
    ll.add(8)
    ll.append(3)
    ll.append(4)
    ll.append(5)
    ll.append(6)
    #8,1,2,3,4,5,6
    ll.travel()
    
    ll.insert(-1,9)
    #9,8,1,2,3,4,5,6
    ll.travel()
    
    ll.insert(3,100)
    #9,8,1,100,2,3,4,5,6
    ll.travel()
    
    ll.insert(10,200)
    #9,8,1,100,2,3,4,5,6,200
    ll.travel()
    ll.remove(100)
    ll.travel()
    ll.remove(9)
    ll.travel()
    ll.remove(200)
    ll.travel()
    
            

          