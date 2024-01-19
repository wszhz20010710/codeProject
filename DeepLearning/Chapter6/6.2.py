import torch
import torch.nn as nn
from d2l import torch as d2l
import numpy as np

class Conv2D(nn.Module):
    # 卷积层
    def __init__(self, kernel_size):
        super().__init__()
        self.weight = nn.Parameter(torch.rand(kernel_size))
        self.bias = nn.Parameter(torch.zeros(1))

    def forward(self, x):
        return corr2d(x, self.weight) + self.bias

def corr2d(X, K):
    h, w = K.shape
    Y = torch.zeros((X.shape[0] - h + 1, X.shape[1] - w + 1))
    for i in range(Y.shape[0]):
        for j in range(Y.shape[1]):
            Y[i, j] = (X[i:i+h, j:j+w] * K).sum()
    return Y


# X = torch.tensor([[0.0, 1.0, 2.0], [3.0, 4.0, 5.0], [6.0, 7.0, 8.0]])
# K = torch.tensor([[0.0, 1.0], [2.0, 3.0]])
# Y = corr2d(X, K)
# print(Y)

# 检测图像不同颜色的边缘
# X = torch.ones((6,8))
# X[:, 2:6] = 0
# K = torch.tensor([[1.0, -1.0]])
# Y1 = corr2d(X, K)
# print(Y1)
# Y2 = corr2d(X.t(), K)
# print(Y2)

conv2d = nn.Conv2d(1,1, kernel_size=(1, 2), bias=False)
X = torch.ones((6, 8))
X[:, 2:6] = 0
K = torch.tensor([[1.0, -1.0]])
Y = corr2d(X, K)

X = X.reshape((1,1,6,8))
Y = Y.reshape((1,1,6,7))
lr = 0.03

for i in range(10):
    Y_hat = conv2d(X)
    l = (Y_hat - Y) ** 2
    conv2d.zero_grad()
    l.sum().backward()
    
    conv2d.weight.data[:] -= lr * conv2d.weight.grad
    if (i+1) % 2 == 0:
        print(f'epoch {i+1}, loss {l.sum():.3f}')