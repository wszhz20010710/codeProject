# 创建一个新集合
my_set = {1, 2, 3}

# 添加元素
my_set.add(4)

# 删除指定元素
my_set.remove(2)

# 删除指定元素，如果不存在不报错
my_set.discard(3)

# 随机删除并返回一个元素
removed_element = my_set.pop()

# 清空集合中的所有元素
my_set.clear()

# 检查指定元素是否存在于集合中
if 1 in my_set:
    print("1 exists in the set.")

# 获取集合的大小
size = len(my_set)

# 创建集合的浅拷贝
new_set = my_set.copy()

# 从可迭代对象中创建一个新集合
iterable = [5, 6, 7]
new_set = set(iterable)

# 获取两个集合的并集
set1 = {1, 2, 3}
set2 = {3, 4, 5}
union_set = set1 | set2

# 获取两个集合的交集
intersection_set = set1 & set2

# 获取两个集合的差集
difference_set = set1 - set2

# 获取两个集合的对称差集
symmetric_difference_set = set1 ^ set2

# 检查一个集合是否为另一个集合的子集
is_subset = set1.issubset(set2)

# 检查一个集合是否为另一个集合的超集
is_superset = set1.issuperset(set2)

# 检查两个集合是否没有共同元素
no_intersection = set1.isdisjoint(set2)

# 将一个集合更新为与另一个集合的并集
set1.update(set2)

# 将一个集合更新为与另一个集合的交集
set1.intersection_update(set2)

# 将一个集合更新为与另一个集合的差集
set1.difference_update(set2)

# 将一个集合更新为与另一个集合的对称差集
set1.symmetric_difference_update(set2)
