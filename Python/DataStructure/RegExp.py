#正则表达式中常用函数
import re

# re.search(pattern, string, flags=0):
# 在字符串中搜索整个文本，尝试找到第一个匹配的子串。
# 返回一个匹配对象（Match），如果未找到则返回None。
text = "Hello, my email is example@example.com. Please contact me!"
pattern = r'\w+@\w+\.\w+'
match = re.search(pattern, text)
if match:
    print("Email found:", match.group())
else:
    print("No email found")

# re.findall(pattern, string, flags=0):
# 在字符串中找到所有匹配的子串，返回一个列表。
pattern = r'\w+@\w+\.\w+'
matches = re.findall(pattern, text)
print("Emails:", matches)

# re.finditer(pattern, string, flags=0):
# 在字符串中找到所有匹配的子串，返回一个迭代器，可以用于遍历匹配对象。
pattern = r'\w+@\w+\.\w+'
for match in re.finditer(pattern, text):
    print("Email found:", match.group())

# re.match(pattern, string, flags=0):
# 从字符串开头开始尝试匹配模式，如果匹配成功返回一个匹配对象，否则返回None。
pattern2 = r'^\d{3}-\d{2}-\d{4}$'  # 匹配格式为：xxx-xx-xxxx 的字符串
social_security_number = "123-45-6789"
if re.match(pattern2, social_security_number):
    print("Valid social security number")
else:
    print("Invalid social security number")
    
# re.sub(pattern, repl, string, count=0, flags=0):
# 将字符串中所有匹配的子串替换为指定的字符串。
# 可以使用count参数指定最多替换的次数。
new_text = re.sub(pattern, "REDACTED", text)
print("Modified Text:", new_text)

