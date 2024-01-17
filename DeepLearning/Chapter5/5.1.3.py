# 在前项传播函数中执行代码
import torch
import torch.nn as nn
from torch.nn import functional as F

device = torch.device('cuda' if torch.cuda.is_available() else 'gpu')
# 有时我们可能希望合并既不是上一层的结果也不是可更新参数的项， 我们称之为常数参数

class FixedHiddenMLP(nn.Module):
    def __init__(self):
        super().__init__()
        self.rand_weight = torch.rand((20, 20), requires_grad=True)
        self.linear = nn.Linear(20, 20)
        
    def forward(self, X):
        X = self.linear(X)
        X = F.relu(torch.mm(X, self.rand_weight) + 1)
        
        while X.abs().sum() > 1:
            X /= 2
        return X.sum()
    
  
class NestMLP(nn.Module):
    def __init__(self):
        super().__init__()
        self.net = nn.Sequential(nn.Linear(20, 64), nn.ReLU(),
                                 nn.Linear(64, 32), nn.ReLU())
        self.linear = nn.Linear(32, 16)

    def forward(self, X):
        return self.linear(self.net(X))
   
X = torch.rand(2, 20)
X.to(device)
net = FixedHiddenMLP()
print(net(X))

# 我们可以混合搭配各种组合块的方法 
chimera = nn.Sequential(NestMLP(), nn.Linear(16, 20), FixedHiddenMLP())
print(chimera(X))
