class TreeNode(object):
    '''建立树的结点'''
    def __init__(self,value):
        self.elem = value
        self.left = None
        self.right = None

class BinaryTree(object):
    '''建立二叉树结构'''
    def __init__(self):
        '''初始化根结点'''
        self.root = None
    
    def add(self,value):
        '''向树中添加元素'''
        node = TreeNode(value)
        if self.root is None:
            self.root = node
            return
        queue = [self.root]
        while queue:
            #读出根结点
            cur_node = queue.pop(0)
            if cur_node.left is None:
                cur_node.left = node
                return
            else:
                queue.append(cur_node.left)
            
            if cur_node.right is None:
                cur_node.right = node
                return
            else:
                queue.append(cur_node.right)
            
    def BreadthTravel(self):
        '''对树进行广度遍历'''
        if self.root is None:
            return
        queue = [self.root]
        while queue:
            cur_node = queue.pop(0)
            print(cur_node.elem,end="")
            if cur_node.left is not None:
                queue.append(cur_node.left)
            if cur_node.right is not None:
                queue.append(cur_node.right)
    
    def PreTravel(self,node):
        '''对树进行先序遍历'''
        if node is None:
            return
        print(node.elem,end="")
        self.PreTravel(node.left)
        self.PreTravel(node.right)
        
    def MidTravel(self,node):
        '''对树进行中序遍历'''
        if node is None:
            return
        self.MidTravel(node.left)
        print(node.elem,end="")
        self.MidTravel(node.right)
    
    def PosTravel(self,node):
        '''对树进行后序遍历'''
        if node is None:
            return
        self.PosTravel(node.left)
        self.PosTravel(node.right)
        print(node.elem,end="")
        
        
        
                

if __name__ == "__main__":
    tree = BinaryTree()
    tree.add(1)
    tree.add(2)
    tree.add(3)
    tree.add(4)
    tree.add(5)
    tree.add(6)
    tree.add(7)
    tree.add(8)
    tree.add(9)
    #            1
    #          /  \
    #         2    3
    #       / \   / \
    #      4  5  6  7
    #     / \
    #    8  9
    #123456789
    tree.BreadthTravel()
    print(" ")
    #124895367
    tree.PreTravel(tree.root)
    print(" ")
    #84251637
    tree.MidTravel(tree.root)
    print(" ")
    #894526731
    tree.PosTravel(tree.root)