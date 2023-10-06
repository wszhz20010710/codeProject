class LinearDictionary(object):
    '''用线性表实现一个字典'''
    def __init__(self):
        '''初始化一个线性表data为list对象'''
        self.data = []
    
    def insert(self,key,value):
        '''插入键值对'''
        #如果存在相应的key则更新value
        for pair in self.data:
            if pair[0] == key:
                pair[1] == value
                return
        #否则建立新的键值对
        self.data.append([key, value])
    
    def search(self,key):
        '''查找key对应的值value'''
        for pair in self.data:
            if pair[0] == key:
                return pair[1]
        return None
    
    def update(self,key,value):
        '''更新键值对'''
        for pair in self.data:
            if pair[0] == key:
                pair[1] = value
                return
        self.data.append([key, value])
    
    def delete(self,key):
        '''删除键值对'''
        for pair in self.data:
            if pair[0] == key:
                self.data.remove(pair)
                return
            
    def is_exist(self,key):
        '''键是否存在'''
        for pair in self.data:
            if pair[0] == key:
                return True
        return False
        
    def keys(self):
        '''遍历所有key'''
        return [pair[0] for pair in self.data]
    
    def values(self):
        '''遍历所有value'''
        return [pair[1] for pair in self.data]
    
    def items(self):
        '''返回所有键值对'''
        return self.data
    
    def is_empty(self):
        '''判断是否为空'''
        return len(self.data) == 0
    
    def size(self):
        '''返回字典大小'''
        return len(self.data)

if __name__ == "__main__":
    dictionary = LinearDictionary()
    dictionary.insert("name", "Alice")
    dictionary.insert("age", 30)
    dictionary.insert("country", "USA")

    print("Name:", dictionary.search("name"))  # 输出 Name: Alice
    print("Age:", dictionary.search("age"))    # 输出 Age: 30

    dictionary.update("age", 31)
    print("Age (updated):", dictionary.search("age"))  # 输出 Age (updated): 31

    dictionary.delete("age")
    print("Contains 'age':", dictionary.is_exist("age"))  # 输出 Contains 'age': False

    print("Keys:", dictionary.keys())         # 输出 Keys: ['name', 'country']
    print("Values:", dictionary.values())     # 输出 Values: ['Alice', 'USA']
    print("Items:", dictionary.items())       # 输出 Items: [['name', 'Alice'], ['country', 'USA']]
    print("Is Empty:", dictionary.is_empty()) # 输出 Is Empty: False
    print("Size:", dictionary.size())         # 输出 Size: 2
            
    
    