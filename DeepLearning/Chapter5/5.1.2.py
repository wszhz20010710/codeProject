# 顺序块
import torch
import torch.nn as nn
from torch.nn import functional as F

device = torch.device('cuda' if torch.cuda.is_available() else 'gpu')

class MySequential(nn.Module):
    def __init__(self, *args):
        super().__init__()
        for block in args:
            self._modules[block] = block
    
    def forward(self, X):
        for block in self._modules.values():
            X = block(X)
        return X
    
X = torch.rand(2, 20)
X.to(device)
net = MySequential(nn.Linear(20, 256), nn.ReLU(), nn.Linear(256, 10))
print(net(X))