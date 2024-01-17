# 层和块
import torch
import torch.nn as nn
from torch.nn import functional as F

# 下面的代码生成一个网络，
# 其中包含一个具有256个单元和ReLU激活函数的全连接隐藏层， 
# 然后是一个具有10个隐藏单元且不带激活函数的全连接输出层
net = nn.Sequential(nn.Linear(20,256), nn.ReLU(), nn.Linear(256, 10))

# 我们一直在通过net(X)调用我们的模型来获得模型的输出。 
# 这实际上是net.__call__(X)的简写。 这个前向传播函数非常简单： 
# 它将列表中的每个块连接在一起，将每个块的输出作为下一个块的输入。
X = torch.rand(2, 20)
print(net(X))