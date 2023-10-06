#子串查找算法

def naive_string_search(text, pattern):
    '''暴力匹配算法'''
    n = len(text)  # 主串长度
    m = len(pattern)  # 子串长度
    
    for i in range(n - m + 1):  # 在主串中遍历可能的起始位置
        j = 0
        while j < m and text[i + j] == pattern[j]:
            j += 1
        if j == m:  # 子串中的所有字符都匹配
            return i  # 返回子串在主串中的起始位置
    
    return -1  # 子串未找到

#以下为测试代码，按住Ctrl+/取消注释
# text = "Hello, World!"
# pattern = "World"
# result = naive_string_search(text, pattern)
# if result != -1:
#     print(f"Pattern found at index {result}")
# else:
#     print("Pattern not found")

def build_pmt(pattern):
    m = len(pattern)
    pmt = [0] * m
    j = 0
    
    for i in range(1, m):
        while j > 0 and pattern[i] != pattern[j]:
            j = pmt[j - 1]
        if pattern[i] == pattern[j]:
            j += 1
        pmt[i] = j
        
    return pmt

def kmp_search(text, pattern):
    n = len(text)
    m = len(pattern)
    pmt = build_pmt(pattern)
    j = 0
    
    for i in range(n):
        while j > 0 and text[i] != pattern[j]:
            j = pmt[j - 1]
        if text[i] == pattern[j]:
            j += 1
        if j == m:
            return i - m + 1
            
    return -1

text = "ABABABABCABABABABCABABABABC"
pattern = "ABABCABAB"
result = kmp_search(text, pattern)
if result != -1:
    print(f"Pattern found at index {result}")
else:
    print("Pattern not found")
