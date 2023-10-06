class LinearSet(object):
    def __init__(self):
        '''初始化'''
        self.data = []

    def add(self, element):
        '''添加新元素，重复不添加'''
        if element not in self.data:
            self.data.append(element)

    def remove(self, element):
        '''删除元素'''
        if element in self.data:
            self.data.remove(element)

    def is_empty(self):
        '''判空'''
        return len(self.data) == 0

    def contains(self, element):
        '''检查是否包含element'''
        return element in self.data

    def size(self):
        '''返回集合大小'''
        return len(self.data)

    def clear(self):
        '''清空集合'''
        self.data = []

    def elements(self):
        '''遍历集合中所有元素'''
        return self.data

    def union(self, other_set):
        '''求并集'''
        new_set = LinearSet()
        new_set.data = self.data.copy()
        for element in other_set.data:
            new_set.add(element)
        return new_set

    def intersection(self, other_set):
        '''求交集'''
        new_set = LinearSet()
        for element in self.data:
            if other_set.contains(element):
                new_set.add(element)
        return new_set

    def difference(self, other_set):
        '''求差集'''
        new_set = LinearSet()
        for element in self.data:
            if not other_set.contains(element):
                new_set.add(element)
        return new_set

if __name__ == "__main__":
    set1 = LinearSet()
    set1.add(1)
    set1.add(2)
    set1.add(3)

    set2 = LinearSet()
    set2.add(3)
    set2.add(4)
    set2.add(5)

    print("Set 1:", set1.elements())  # 输出 Set 1: [1, 2, 3]
    print("Set 2:", set2.elements())  # 输出 Set 2: [3, 4, 5]

    set3 = set1.union(set2)
    print("Union:", set3.elements())   # 输出 Union: [1, 2, 3, 4, 5]

    set4 = set1.intersection(set2)
    print("Intersection:", set4.elements())  # 输出 Intersection: [3]

    set5 = set1.difference(set2)
    print("Difference:", set5.elements())     # 输出 Difference: [1, 2]
