class SinCycLinkListNode(object):
    '''建立单向循环链表结点'''
    def __init__(self,elem):
        self.elem = elem
        self.next = None
        

class SinCycLinkList(object):
    '''建立单向循环链表'''
    def __init__(self,node = None):
        self._head = node
        if node != None:
            node.next = node
         
    def is_empty(self):
        '''判断链表是否为空'''
        return self._head is None
    
    def length(self):
        '''求链表长度'''
        #链表为空直接返回0
        if self.is_empty():
            return 0
        else:
            cur = self._head
            count = 1
            while cur.next != self._head:
                count += 1
                cur = cur.next
            return count
    
    def travel(self):
        '''遍历链表'''
        #考虑链表为空的情况
        if self.is_empty():
            return
        else:
            cur = self._head
            while cur.next != self._head:
                print(cur.elem,end = " ")
                cur = cur.next
            #退出循环时cur指向尾结点，但尾结点元素未打印
            print(cur.elem,end = " ")
            print("")
           
    def add(self,item):
        '''在链表头部插入元素''' 
        node = SinCycLinkListNode(item)
        #考虑空链表的情况
        if self.is_empty():
            self._head = node
            node.next = node
        else:
            #先找尾结点
            cur = self._head
            while cur.next != self._head:
                cur = cur.next
            #退出循环时cur指向尾结点
            node.next = self._head
            self._head = node
            #将尾结点cur指向node
            cur.next = node
            
    def append(self,item):
        '''在链表尾部插入元素'''
        node = SinCycLinkListNode(item)
        #考虑空链表情况
        if self.is_empty():
            self._head = node
            node.next = node
        else:
            cur = self._head
            while cur.next != self._head:
                cur = cur.next
            #退出循环时cur指向尾结点
            #先将node的next指向头节点
            node.next = self._head
            #再将cur的next指向新的尾结点node
            cur.next = node
            
    def insert(self,pos,item):
        '''在链表指定位置插入元素'''
        node = SinCycLinkListNode(item)
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
    
    def remove(self,item):
        '''删除链表中的元素'''
        #先考虑空链表
        if self.is_empty():
            return
        #定义两个指针pre和cur，pre在cur前一个位置
        cur = self._head
        pre = None
        #首先对链表进行遍历
        while cur.next != self._head:
            if cur.elem == item:
                #判断是否是头结点
                #头结点
                if cur == self._head:
                    #先找尾结点，定义新指针curr
                    curr = self._head
                    while curr.next != self._head:
                        curr = curr.next
                    self._head = cur.next
                    curr.next = self._head
                else:
                    #中间结点
                    pre.next = cur.next
                return
                #此时删除搜索到的第一个元素，若想删除所有item
                #则将return改为cur = cur.next

            else:
                pre = cur
                cur = cur.next
        #退出循环时，cur指向尾结点，但对尾结点没有进行判断
        #尾结点
        if cur.elem == item:
            #考虑只有一个结点的情况
            if cur == self._head:
                self._head = None
            else:
                pre.next = cur.next
                             
    def search(self,item):
        '''在链表中搜索元素'''
        #首先考虑空链表情况,直接返回False
        if self.is_empty():
            return False
        else:
            cur = self._head
            while cur.next != self._head:
                if cur.elem == item:
                    return True
                else:
                    cur = cur.next
            #退出循环时cur指向尾结点，但对尾结点没有进行判断
            if cur.elem == item:
                return True
            #此时完成了对链表中所有元素的判断，若没有item则返回False
            return False


if __name__ == "__main__":
    ll = SinCycLinkList()
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
    