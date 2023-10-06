# 创建一个新字典
my_dict = {"name": "Alice", "age": 30}

# 通过键访问值
name = my_dict["name"]

# 向字典中添加或修改键值对
my_dict["city"] = "New York"
my_dict["age"] = 31

# 删除指定键的键值对
del my_dict["age"]

# 检查指定键是否存在于字典中
if "name" in my_dict:
    print("Name exists in the dictionary.")

# 获取包含所有键的列表
keys = my_dict.keys()

# 获取包含所有值的列表
values = my_dict.values()

# 获取包含所有键值对的列表，每个元素是一个元组 (key, value)
items = my_dict.items()

# 根据键获取对应的值，如果键不存在则返回默认值
age = my_dict.get("age", 0)

# 根据键删除并返回对应的值，如果键不存在则返回默认值
city = my_dict.pop("city", "Unknown")

# 删除并返回字典中的一个键值对（通常是最后一个）
key, value = my_dict.popitem()

# 清空字典中的所有键值对
my_dict.clear()

# 返回字典中键值对的数量
size = len(my_dict)

# 创建字典的浅拷贝
new_dict = my_dict.copy()

# 将其他字典的键值对更新到当前字典中
other_dict = {"country": "USA"}
my_dict.update(other_dict)

# 如果键存在于字典中，则返回其值；如果不存在，则插入键及默认值，并返回默认值
age = my_dict.setdefault("age", 0)

# 创建一个新字典，使用可迭代对象中的元素作为键，所有的值都设置为给定的值
keys = ["name", "age", "city"]
default_value = "Unknown"
new_dict = dict.fromkeys(keys, default_value)

# 返回一个字典视图，包含键值对元素的迭代器
items_view = my_dict.items()

# 返回一个字典视图，包含字典中所有键的迭代器
keys_view = my_dict.keys()

# 返回一个字典视图，包含字典中所有值的迭代器
values_view = my_dict.values()
