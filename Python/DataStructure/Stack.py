class StackUnderFlow(ValueError):
    '''定义栈下溢异常，即空栈访问'''
    pass

class SStack(object):
    '''用顺序表实现栈,直接使用list对象'''
    def __init__(self):
        #初始化_items为list对象
        self._items = []
        
    def is_empty(self):
        '''判断栈是否为空'''
        return self._items == []
    
    def push(self,item):
        '''将元素item压入堆栈'''
        self._items.append(item)
        
    def pop(self):
        '''弹出栈顶元素并且删除'''
        if self._items == []:
            raise StackUnderFlow("in SStack.pop()")
        return self._items.pop()
    
    def top(self):
        '''返回栈顶元素但不删除'''
        if self._items == []:
            raise StackUnderFlow("in SStack.top()")
        return self._items[-1]
    
    def size(self):
        '''求堆栈大小'''
        return len(self._items)
    


#首先引用单链表结点
import SingleLinkList
from SingleLinkList import SingleLinkNode

class LStack(object):
    '''用单向链表实现栈,直接使用list对象'''
    '''大部分函数和单向链表中相同'''
    def __init__(self,node=None):
        #初始化_head为SingleLinkNode对象
        self._head = None
        
    def is_empty(self):
        '''判断栈是否为空'''
        return self._head is None
    
    def push(self,item):
        '''将元素elem压入堆栈,方法同add()'''
        node = SingleLinkNode(item)
        node.next = self._head
        self._head = node
        
    def pop(self):
        '''弹出栈顶元素并且删除'''
        if self._head is None:
            raise StackUnderFlow("in LStack.pop()")
        #定义cur指针指向栈顶元素
        cur = self._head
        #删除栈顶元素
        self._head = cur.next
        #返回被删除的栈顶元素
        return cur.elem
    
    def top(self):
        '''返回栈顶元素但不删除'''
        if self._head is None:
            raise StackUnderFlow("in LStack.top()")
        return self._head.elem
        
    def size(self):
        '''求堆栈大小,同length()'''
        #current为游标，用来移动遍历结点
        current = self._head
        #count用来记录结点数量
        count = 0
        while current != None:
            count += 1
            current = current.next
        return count
        
        
if __name__ == "__main__":
    stack1 = SStack()
    stack1.push("hello")
    stack1.push("world")
    stack1.push("cast")
    print(stack1.is_empty())
    print(stack1.size())
    print(stack1.top())
    print(stack1.pop())
    print(stack1.pop())
    print(stack1.pop())
    print(stack1.size())
    print(stack1.is_empty())
    print("")
    stack2 = LStack()
    stack2.push("hello")
    stack2.push("world")
    stack2.push("cast")
    print(stack2.is_empty())
    print(stack2.size())
    print(stack2.top())
    print(stack2.pop())
    print(stack2.pop())
    print(stack2.pop())
    print(stack2.size())  
    print(stack2.is_empty())