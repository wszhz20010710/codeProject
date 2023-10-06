#介绍字符串相关操作函数

# len(): 返回字符串的长度（字符数量）.
my_string = "Hello, World!"
length = len(my_string)
print(length)  # 输出: 13



# str(): 将其他数据类型转换为字符串。



# upper() 和 lower(): 将字符串中的字符转换为大写和小写。
original_string = "Hello, World!"
uppercase_string = original_string.upper()
lowercase_string = original_string.lower()
print(uppercase_string)  # 输出: "HELLO, WORLD!"
print(lowercase_string)  # 输出: "hello, world!"



# capitalize(): 将字符串的首字母大写。
text = "hello, world!"
capitalized_text = text.capitalize()
print(capitalized_text)  # 输出: "Hello, world!"



# title(): 将字符串中每个单词的首字母大写。
text = "hello, world!"
title_text = text.title()
print(title_text)  # 输出: "Hello, World!"



# strip(), lstrip() 和 rstrip(): 去除字符串开头和末尾的空白字符。
text = "   Hello, World!   "
stripped_text = text.strip()
print(stripped_text)  # 输出: "Hello, World!"



# find() 和 index(): 查找子串在字符串中的位置。
text = "Hello, World!"
index = text.find("World")
print(index)  # 输出: 7



# replace(): 替换指定的子串为另一个子串。
text = "Hello, World!"
new_text = text.replace("Hello", "Hi")
print(new_text)  # 输出: "Hi, World!"



# split(): 根据分隔符将字符串拆分成子串列表。
text = "apple, banana, cherry"
fruits = text.split(", ")
print(fruits)  # 输出: ['apple', 'banana', 'cherry']



# join(): 将字符串列表中的元素连接成一个字符串。
fruits = ['apple', 'banana', 'cherry']
text = ", ".join(fruits)
print(text)  # 输出: "apple, banana, cherry"



# startswith() 和 endswith(): 检查字符串是否以指定的前缀或后缀开始或结束。
    # startswith(prefix[, start[, end]]):
    # 用于检查字符串是否以给定的前缀开头。
    # 可以通过可选的 start 和 end 参数指定要检查的子串范围
text1 = "Hello, World!"
# 检查是否以特定前缀开头
result1 = text1.startswith("Hello")
print(result1)  # 输出: True
result1 = text1.startswith("World")
print(result1)  # 输出: False
    # endswith(suffix[, start[, end]]):
    # 用于检查字符串是否以给定的后缀结尾。
    # 可以通过可选的 start 和 end 参数指定要检查的子串范围
text2 = "Hello, World!"
# 检查是否以特定后缀结尾
result2 = text2.endswith("World!")
print(result2)  # 输出: True
result2 = text2.endswith("Hello")
print(result2)  # 输出: False



# count(): 计算指定子串在字符串中出现的次数。
    # count(substring, start, end)
    # 用于计算指定子串在字符串中出现的次数。
    # 可以通过可选的 start 和 end 参数指定要计算的子串范围
text = "Hello, Hello, World!"
# 计算指定子串出现的次数
count_hello = text.count("Hello")
print(count_hello)  # 输出: 2
count_world = text.count("World")
print(count_world)  # 输出: 1  



# isalpha(), isdigit(), isalnum(): 检查字符串是否只包含字母、数字、字母和数字的组合。
    # isalpha():用于检查字符串是否只包含字母字符。返回 True 如果字符串中所有字符都是字母，否则返回 False。
text_alpha = "Hello"
text_mixed = "Hello123"
result_alpha = text_alpha.isalpha()
result_mixed = text_mixed.isalpha()
print(result_alpha)  # 输出: True
print(result_mixed)  # 输出: False
    # isdigit():用于检查字符串是否只包含数字字符。返回 True 如果字符串中所有字符都是数字，否则返回 False。
text_digit = "12345"
text_mixed = "Hello123"
result_digit = text_digit.isdigit()
result_mixed = text_mixed.isdigit()
print(result_digit)  # 输出: True
print(result_mixed)  # 输出: False
    # isalnum():用于检查字符串是否只包含字母和数字字符的组合。返回 True 如果字符串中所有字符都是字母或数字，否则返回 False
text_alnum = "Hello123"
text_special = "Hello!123"
result_alnum = text_alnum.isalnum()
result_special = text_special.isalnum()
print(result_alnum)  # 输出: True
print(result_special)  # 输出: False



# format(): 格式化字符串，用于将变量插入字符串中。
    # format(*args, kwargs)
    # 用于将变量的值插入到字符串中的占位符位置。
    # 可以使用位置参数（*args）或关键字参数（**kwargs）来传递要插入的值。
name = "Alice"
age = 30
# 使用位置参数
formatted_string = "My name is {} and I am {} years old.".format(name, age)
print(formatted_string)  # 输出: "My name is Alice and I am 30 years old."
# 使用关键字参数
formatted_string = "My name is {n} and I am {a} years old.".format(n=name, a=age)
print(formatted_string)  # 输出: "My name is Alice and I am 30 years old."
    # format() 方法通过大括号 {} 来指示要插入变量的位置。
    # 您可以使用位置参数或关键字参数，也可以混合使用两者。在字符串中的每个占位符位置都会与参数列表中的相应值进行匹配。
    # 此外，还可以在大括号中指定格式说明符，例如：{:d} 表示整数，{:.2f} 表示带有两位小数的浮点数等。  
pi = 3.14159
formatted_pi = "The value of pi is {:.2f}".format(pi)
print(formatted_pi)  # 输出: "The value of pi is 3.14"



# encode() 和 decode(): 将字符串编码为字节流或从字节流解码为字符串。
    # encode(encoding="utf-8", errors="strict"):用于将字符串编码为字节流。
    # encoding 参数指定要使用的字符编码（默认为 "utf-8"）。
    # errors 参数指定在无法编码某些字符时的处理方式（默认为 "strict"，意味着引发 UnicodeEncodeError）。
text = "Hello, World!"
encoded_bytes = text.encode("utf-8")
print(encoded_bytes)  # 输出: b'Hello, World!'
    # decode(encoding="utf-8", errors="strict"):用于将字节流解码为字符串。
    # encoding 参数指定字节流的字符编码（默认为 "utf-8"）。
    # errors 参数指定在无法解码某些字节时的处理方式（默认为 "strict"，意味着引发 UnicodeDecodeError）
encoded_bytes = b'Hello, World!'
decoded_text = encoded_bytes.decode("utf-8")
print(decoded_text)  # 输出: "Hello, World!"



# slice操作: 使用索引来获取字符串中的子串。
    # string[start:end:step]
    # start：切片的起始索引（包含在切片中）。
    # end：切片的结束索引（不包含在切片中）。
    # step：切片的步长，表示每次跳过的字符数（默认为 1）。
text = "Hello, World!"

# 提取前5个字符
substring1 = text[0:5]  # 或者 text[:5]
print(substring1)  # 输出: "Hello"

# 提取从第7个字符到倒数第2个字符
substring2 = text[6:-2]
print(substring2)  # 输出: "World"

# 每隔两个字符提取一个字符
substring3 = text[::2]
print(substring3)  # 输出: "Hlo ol!"

# 逆序提取字符串
substring4 = text[::-1]
print(substring4)  # 输出: "!dlroW ,olleH" 